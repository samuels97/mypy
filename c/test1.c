/*input 2 numbers and output their sum*/
#include <stdio.h>

main(){
  int mysum, first_no, second_no;
  
  printf("Enter two numbers to be added: ");
  scanf("%d %d", &first_no, &second_no);
  
  mysum = first_no + second_no;
  
  printf("The sum of %d and %d is %d", first_no, second_no, mysum);
  
  return 0;
}
