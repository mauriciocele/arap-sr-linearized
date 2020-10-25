#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#else /* assume UNIX */
#include <sys/times.h>  // times() function
#include <unistd.h>     // sysconf() function
#endif /* WIN32/UNIX */

#include "timing.h"

// The timer resolutions for both possible platforms are stored in these variables
#ifdef WIN32
	static LARGE_INTEGER s_Performancetimerresolution;
#else /* assume UNIX */
	static long s_Clktck;  
#endif /* WIN32/UNIX */

// true once one-time initialization has been done
static int s_TimeInitDone = 0;

// when was timeElapsed() last called?
static double s_LastTimeElapsed = -1.0;

static int u_timeInit() {
#ifndef WIN32
	struct tms TMS;
#endif
	if (s_TimeInitDone) {
		printf("timeInit(): already called?\n");
		return -1;
	}

#ifdef WIN32
	if (!QueryPerformanceFrequency(&s_Performancetimerresolution)) {
		printf("timeInit(): could not QueryPerformanceFrequency()\n");
		return -1;
	}
#else /* assume UNIX */
	// get size of clock tick
	if ( (s_Clktck = sysconf(_SC_CLK_TCK)) < 0) {
	    printf("timeInit(): sysconf() error\n");
	    return -1;
	}
#endif /* WIN32 or UNIX */

	s_TimeInitDone = 1;

	return UTERR_OK;
}

/*
returns time (in seconds) passed, since some arbitrary point in the past (e.g. client or workstation startup)
*/
double u_timeGet() {
	int err;
#ifdef WIN32
	LARGE_INTEGER counter;
#else /* assume UNIX */
	unsigned int real;
	struct tms TMS;
	double e,t;
#endif /* WIN32 or UNIX */

	// check for initialization
	if (!s_TimeInitDone) if ( (err = u_timeInit()) != UTERR_OK) return -1.0;

#ifdef WIN32
	if (!QueryPerformanceCounter(&counter)){
		printf("timeGet(): could not QueryPerformanceCounter()\n");
		return -1.0;
	}
	return (double)(counter.QuadPart) / (double)s_Performancetimerresolution.QuadPart;
#else /* assume UNIX */
	// get current times
	// todo: adjust for long up-times
	if ( (real = (unsigned int)times(&TMS)) == (unsigned int)-1) {
	    printf("timeGet(): times() error\n");
	    return -1.0;
	}

	// process results; return elapsed time
	return (double)(real) / (double)s_Clktck;
#endif /* WIN32 or UNIX */
}

/*
returns time (in seconds) passed since last call to this function (0.0 the first time)
*/
double u_timeElapsed() {
	double t, temp;

	if ( (t = u_timeGet()) < 0.0) return -1.0;
	
	if (s_LastTimeElapsed < 0) {
		s_LastTimeElapsed = t;
		return 0.0;
	}
	else {
		temp = s_LastTimeElapsed;
		s_LastTimeElapsed = t;
		return t - temp;
	}
}
