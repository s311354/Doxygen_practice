#include "bitwise.h"

/** This function is setting a specific bit to be 1...
 *    @param Input value
 *    @param Specific location
 *    @return Set result
 */
int setbit(int input, int bitwise) {
	bitwise = bitwise - 1;
	return input | (1 << bitwise); // OR
}

/** This function is clearing a specific bit to be 0...
 *    @param Input value
 *    @param Specific location
 *    @return Cleared result
 */
int clearbit(int input, int bitwise) {
	bitwise = bitwise - 1;
	return input & (~(1 << bitwise)); // AND and NOT
}

/** This function is used to inverse a specific bit...
 *    @param Input value
 *    @param Specific location
 *    @return Revered result
 */
int inversebit(int input, int bitwise) {
	bitwise = bitwise - 1;
	return input ^ (1 << bitwise); // XOR
}

/** This function is used to swap integer data a and b without temporary variable...
 *    @param Integer data a
 *    @param Integer data b
 *    @return none
 */
void swap(int data_a, int data_b) {
	data_a = data_a ^ data_b;
	data_b = data_a ^ data_b;
	data_a = data_a ^ data_b;
}
