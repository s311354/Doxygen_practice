#ifndef STRUCT_PROCESS_H_
#define STRUCT_PROCESS_H_

/** Dummy structure
 */
typedef struct STRUCTTAG_T {
	int memberA; /**< struct value 1 */
	int memberB; /**< struct value 1 */
} STRUCTTAG, *PSTRUCTTAG;

void struct_init(PSTRUCTTAG p_tag, int memberA, int memberB);

void struct_free(PSTRUCTTAG p_tag);

#endif /* STRUCT_PROCESS_H_ */
