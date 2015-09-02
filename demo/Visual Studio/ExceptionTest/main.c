#include "exceptions.h"
#include <stdio.h>
#include <stdlib.h>


void throwException3(){
	throw(NoFileFound);
}

void throwException(){
	try{
		throwException3();
	}
	catch{
		on(NoFileFound)
			printf("No file found\n");
	}
	throw(NullPointer);
}
void throwException2(){
	try{
		throwException();
	}
	catch{
		on(NullPointer)
			printf("Null pointer\n");
	}
	throw(NegativeArraySize);
}
void throwException4(){
	try{
		throwException2();
	}
	catch{
		on(NegativeArraySize)
			printf("Negative Size Array\n");
	}
	throw(ClassNotSupported);
}

int main(){

	try{
		//throwException();
		//throwException2();
		//throwException3();
		throwException4();
		
		printf("Ex1\n");
	}
	catch{
		on(NegativeArraySize)
			printf("Doesnt print\n");
		on(NullPointer)
			printf("Ok\n");
		on(NoFileFound)
			printf("No file\n");
		on(ClassNotSupported)
			printf("ClassNotSupported\n");
	}

	getchar();
	return 0;
}