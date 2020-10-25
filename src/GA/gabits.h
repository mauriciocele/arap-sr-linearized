// This program is fee software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.


// Copyright 2007, Daniel Fontijne, University of Amsterdam -- fontijne@science.uva.nl


#ifndef _GA_BITS_H_
#define _GA_BITS_H_

/**
    * returns the number of 1 bits in 'i'
    */
inline int bitCount(int i) {
	// Note that unsigned shifting (>>>) is not required.
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i + (i >> 4)) & 0x0F0F0F0F;
	i = i + (i >> 8);
	i = i + (i >> 16);
	return i & 0x0000003F;
}

/** returns the number of 0 bits before the first 1 bit in 'i'
    * For example if i = 4 (100 binary), then 29 (31 - 2) is returned.
    */
inline int numberOfLeadingZeroBits(int i) {
	// Note that unsigned shifting (>>>) is not required.
	i = i | (i >> 1);
	i = i | (i >> 2);
	i = i | (i >> 4);
	i = i | (i >> 8);
	i = i | (i >>16);
	return bitCount(~i);
}
    
/**
    * returns the number of 0 bits after the last 1 bit in <code>i</code>
    * <p>For example if i = 4 (100 binary), then 2 is returned.
    */
inline int numberOfTrailingZeroBits(int i) {
	return bitCount(~i & (i - 1));
}


/** returns in the index [-1 31] of the highest bit that is on in 'i' (-1 is returned if no bit is on at all (i == 0)) */
inline int highestOneBit(int i) {
	return 31 - numberOfLeadingZeroBits(i);
}

/** returns in the index [0 32] of the lowest bit that is on in 'i' (32 is returned if no bit is on at all (i == 0))*/
inline int lowestOneBit(int i) {
	return numberOfTrailingZeroBits(i);
}
    


/**
    * returns the number of 1 bits in 'i'
    */
inline int bitCount16(int i) {
	// Note that unsigned shifting (>>>) is not required.
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i + (i >> 4)) & 0x0F0F0F0F;
	i = i + (i >> 8);
	return i & 0x0000001F;
}



/** returns the number of 0 bits before the first 1 bit in 'i'
    * For example if i = 4 (100 binary), then 13 (15 - 2) is returned.
    */
inline int numberOfLeadingZeroBits16(int i) {
	// Note that unsigned shifting (>>>) is not required.
	i = i | (i >> 1);
	i = i | (i >> 2);
	i = i | (i >> 4);
	i = i | (i >> 8);
	return bitCount16(~i);
}
    
/**
    * returns the number of 0 bits after the last 1 bit in <code>i</code>
    * <p>For example if i = 4 (100 binary), then 2 is returned.
    */
inline int numberOfTrailingZeroBits16(int i) {
	return bitCount16(~i & (i - 1));
}


/** returns in the index [-1 15] of the highest bit that is on in 'i' (-1 is returned if no bit is on at all (i == 0)) */
inline int highestOneBit16(int i) {
	return 15 - numberOfLeadingZeroBits16(i);
}

/** returns in the index [0 16] of the lowest bit that is on in 'i' (16 is returned if no bit is on at all (i == 0))*/
inline int lowestOneBit16(int i) {
	return numberOfTrailingZeroBits16(i);
}



#endif /* _GA_BITS_H_ */
