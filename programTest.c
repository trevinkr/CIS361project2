 //*****************************************************
 // programTest.c -Used for testing Project2
 //
 // @author Kristopher Trevino
 // November 8, 2016
 // ****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mystruct {
    int data ;
};

int main ( int argc , char *argv[] ){

if ( argc != 2){
    exit(1);
}
 
int _myvar8ble, var2, variable = 2;
int count = 0;
char str[15] = "string constant will not be identifier"; 

//Comments should not be an identifier
//Should not be identifier

struct mystruct s ;

if ( count == 0 ){
    var2 = 1;
    variable = 3;
    count = count + 1;
} else {
    if ( count == 1 ){
        _myvar8ble = 1;
        _myvar8ble = 1 + count ;
        s.data = _myvar8ble ; 
        //one more comment not identifier
    } 
}

printf ( "My results: %d\n",  count );

return 0;
}


