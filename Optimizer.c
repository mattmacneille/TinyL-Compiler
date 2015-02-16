/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2014                                *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;
	Instruction *instr1, *instr2, *instr3;
	int opt_flag, opt_calc;


	head = ReadInstructionList(stdin);
	
        /* ---  FIRST: ALGEBRAIC SIMPLIFICATION PASS --- */

	if (!head) {
		ERROR("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */
	instr1=(Instruction*)malloc(sizeof(head));
	instr2=(Instruction*)malloc(sizeof(head));
	instr3=(Instruction*)malloc(sizeof(head));
	instr1=head;
	instr2=instr1->next;
	instr3=instr2->next;
	while(instr3){
		if((instr1->opcode==LOADI&&instr2->opcode==LOAD)||(instr1->opcode==LOAD&&instr2->opcode==LOADI)){
			if(instr1->opcode==LOADI&&instr1->field2==0){
				switch(instr3->opcode){
					case ADD:
						instr1->opcode=LOAD;
						instr1->field1=instr3->field1;
						instr1->field2=instr2->field2;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
						instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}	
						continue;
					case MUL:
						instr1->opcode=LOADI;
						instr1->field1=instr3->field1;
						instr1->field2=0;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}
						continue;	
					default:
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}
						continue;	
				}

			}
			if(instr2->opcode==LOADI&&instr2->field2==0){
				switch(instr3->opcode){
					case ADD:
						
		
						instr1->field1=instr3->field1;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}	
						continue;
					case MUL:
						instr1->opcode=LOADI;
						instr1->field2=0;
						instr1->field1=instr3->field3;
						instr1->next=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
					
						}	
						continue;
					case SUB:
						instr1->field1=instr3->field1;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}	
						continue;
					default:
						instr1=instr1->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}	
						continue;
					}

				}
				if((instr1->opcode==LOADI&&instr2->opcode==LOAD&&instr1->field2==1)||(instr2->opcode==LOADI&&instr1->opcode==LOAD&&instr2->field2==1)){
					switch(instr3->opcode){
						case MUL:
							if(instr1->opcode==LOADI){
								instr1->field2=instr2->field2;
							}
							instr1->opcode=LOAD;
							instr1->field1=instr3->field1;
							instr1->next=instr3->next;
							instr1=instr3->next;
							if(instr1){
								instr2=instr1->next;
								if(instr2){
									instr3=instr2->next;
								}else{
									break;
								}
							}else{
								break;
	
							}	
							continue;
						default:
						instr1=instr1->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}	
					}

				}


		}
		if(instr1->opcode==LOAD&&instr2->opcode==LOAD&&instr1->field2==instr2->field2){
			switch(instr3->opcode){
				case SUB:
					instr1->opcode=LOADI;
					instr1->field2=0;
					instr1->field1=instr3->field1;
					instr1->next=instr3->next;
					instr1=instr1->next;
					if(instr1){
						instr2=instr1->next;
						if(instr2){
							instr3=instr2->next;
						}else{
							break;
						}
					}else{
						break;
	
					}	
				
				default:
					instr1=instr1->next;
					if(instr1){
						instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
					}else{
						break;
	
					}
					continue;	
			}
		}
					
	instr1=instr1->next;
	if(instr1){
		instr2=instr1->next;
		if(instr2){
			instr3=instr2->next;
		}else{
			break;
		}
	}else{
		break;
	
	}	
	
		
	}
		
        /* --- SECOND: CONSTANT FOLDING PASS --- */

	if (!head) {
		ERROR("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */
	instr1=head;
	instr2=instr1->next;
	instr3=instr2->next;
	
	while(instr3){
		if(instr1->opcode==LOADI&&instr2->opcode==LOADI){
			if((instr3->field2==instr1->field1&&instr3->field3==instr2->field1)||(instr3->field2==instr2->field1&&instr3->field3==instr1->field1)){
				switch(instr3->opcode){
					case ADD:
						instr1->field2=instr1->field2+instr2->field2;
						instr1->field1=instr3->field1;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}
						continue;
					case MUL:
						instr1->field2=instr1->field2*instr2->field2;
						instr1->field1=instr3->field1;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}
						continue;
					case SUB:
						instr1->field2=instr1->field2-instr2->field2;
						instr1->field1=instr3->field1;
						instr1->next=instr3->next;
						instr1=instr3->next;
						if(instr1){
							instr2=instr1->next;
							if(instr2){
								instr3=instr2->next;
							}else{
								break;
							}
						}else{
							break;
	
						}
						continue;
					default:
						instr1=instr1->next;
						if(instr1){
							instr2=instr1->next;
								if(instr2){
									instr3=instr2->next;
								}else{
									break;
								}	
						}else{
							break;
	
						}
						continue;				
				}
				
			}
				



			
			





		}







		instr1=instr1->next;
		if(instr1){
			instr2=instr1->next;
			if(instr2){
				instr3=instr2->next;
			}else{
				break;
			}
		}else{
			break;
	
		}	

	}



	PrintInstructionList(stdout, head);
	DestroyInstructionList(head);
	return EXIT_SUCCESS;
}
