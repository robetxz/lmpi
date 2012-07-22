#include <stdio.h>
int main(void)
{
	int num,rank;
	scanf("%d %d",&num, &rank);
	//int rank = myid;
	int depth = 1;
	int flag = 0;
	while(num > 1) {
		if(rank < num){
			flag = num % 2;
			if(rank % 2 != 0){
				//MPI_Send(to (rank-1)*depth);
				printf("Send to %d\n", (rank - 1) * depth);
				rank *= num;
				break;
			}
			else{
				if(!(flag && (rank == (num - 1)))) {
					//MPI_Recv(from (rank+1)*depth);
					//Union_opt();
					printf("Recv from %d\n", (rank+1)*depth);
				}
				rank /= 2;
			}
			depth *= 2;
		}
		num = num / 2 + flag;
	}
	return 0;
}

/* example of 8(power-of-two) processes
   myid	0	1	2	3	4	5	6	7	
   rank	0	1	2	3	4	5	6	7
   num	8

   after step1: 
   myid	0	1	2	3	4	5	6	7	
   rank	0	8	1	24	2	40	3	56
   num	4

   after step2:
   myid	0	1	2	3	4	5	6	7	
   rank	0	8	4	24	1	40	12	56
   num	2

   after step3:
   myid	0	1	2	3	4	5	6	7	
   rank	0	8	4	24	2	40	12	56
   num	1	

   end of loop
 */

/* example of 6(just even) processes
   myid	0	1	2	3	4	5
   rank	0	1	2	3	4	5	
   num	6

   after step1:
   myid	0	1	2	3	4	5
   rank	0	6	1	18	2	30
   num	3

   after step2:
   myid	0	1	2	3	4	5
   rank	0	6	3	9	1	15
   num	1

   after step3:
 */

