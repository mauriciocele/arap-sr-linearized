/** \file util.h
File contains various utility functions.
*/
#ifndef UTIL_CM
#define UTIL_CM
#include <iostream>
#include <string>

static void check_error (bool expr, const std::string & message);
static void check_warn (bool expr, const std::string & message);
static void usage();

/** If expression \a expr is true, \a message is output and program terminates.
\param expr: Exression to check
\param message: Error message to output.
*/
static void check_error (bool expr, const std::string & message) {
   if (expr) {
      std::cerr << "Error: " << message << std::endl;
      exit(1);
   }
}

/** If expression \a expr is true, warning \a message is output.
\param expr: Exression to check
\param message: Warning message to output.
*/
static void check_warn (bool expr, const std::string & message) {
   if (expr)
      std::cerr << "Warning: " << message << std::endl;
}

#endif

