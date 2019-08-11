#include "struct_process.h"

/** This function is assigning initial value in the structure...
 *    @param Pass a pointer-to-structure
 *    @param Assign data to member A
 *    @param Assign data to member B
 *    @return none
 */
void struct_init(PSTRUCTTAG p_tag, int memberA, int memberB) {

	p_tag->memberA = memberA;
	p_tag->memberB = memberB;

}

/** This function is freeing memory...
 *    @param Pass a pointer-to-structure.
 *    @return none
 */
void struct_free(PSTRUCTTAG p_tag) {
}
