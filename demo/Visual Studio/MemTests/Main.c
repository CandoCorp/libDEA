#include <stdio.h>
#include "MemManagement.h"
#include "exceptions.h"
#include "debugSys.h"
#include <stdbool.h>

typedef struct Empleado{
	char nombre[10];
	int id;
}Empleado;

int main(){
	set_default_error_stream("err.txt");
	set_default_debug_print_stream("out.txt");

	debug_on();

	char *temp = NEW(char);
	int *int_temp = NEW(int);
	long long int *int64 = NEW(long long int);
	char str[] = "Test string";
	bool flag = -2;
	Empleado empl = { .nombre = "kevin", .id = 1 };
	Empleado *emplptr = NEW(Empleado);

	printf("%d\n",get_debug_flag());
	
	DELETE(temp);
	DELETE(str);
	DELETE(int64);
	DELETE(int_temp);
	debug_all_levels
		DELETE(emplptr);
	DELETE(&empl);

	debug_off();

	getchar();

	return 0;
}