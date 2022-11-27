#include <iostream>
#include <stdio.h>
#include <cstring>

char entrada[100];
char *next = entrada;
bool term(char token){
    if(*next != '\0'){
        return *next++ == token;
    }else
        return false;
}

bool D();
bool T();
bool T1();
bool T2();
bool L();
bool K();
bool K1();
bool K2();
bool K3();
bool R();
bool R1();
bool R2();
bool R3();
bool R4();
bool I();
bool I1();
bool I2();
bool I3();
bool I4();
bool I5();
bool I6();
bool N();
bool N1();
bool N2();
bool N3();
bool N4();
bool N5();

bool D() {
    return  T() && L();
}


bool T() {
    char* save = next;
    return T1() || (next = save, T2());
}

bool T1() {
    return term('i') && term('_');
}
bool T2() {
    return term('f') && term('_');
}

bool L() {
    return  I() && K();
}


bool K() {
    char* save = next;
    return K1() || (next = save, K2());
}

bool K1() {
    return term(',') && K3();
}
bool K2() {
    return true ;
}

bool K3() {
    return I() && K();
}

bool R() {
    char* save = next;
    return R1() || (next = save, R2());
}

bool R1() {
    return term('[') && R3();
}
bool R2() {
    return true ;
}

bool R3() {
    return N() && R4();
}

bool R4() {
    return term(']') && R();
}

bool I() {
    char* save = next;
    return I1() || (next = save, I2())|| (next = save, I3());
}

bool I1() {
    return I4() && R();
}
bool I2() {
    return I5() && R();
}
bool I3() {
    return I6() && R();
}

bool I4() {
    return term('a');
}
bool I5() {
    return term('b');
}
bool I6() {
    return term('c');
}

bool N() {
    char* save = next;
    return N1() || (next = save, N2())|| (next = save, N3())
    || (next = save, N4()) || (next = save, N5());
}

bool N1() {
    return term('1');
}
bool N2() {
    return term('2');
}
bool N3() {
    return term('3');
}
bool N4(){
    return term('4');
}
bool N5(){
    return term('5');
}

int main() {
    strcpy(entrada, "f_a,,b,c");

    if (D() && *next == '\0') {
        std::cout << ("Aceptado") << std::endl;
    }
    else
        std::cout << ("No Aceptado") << std::endl;
}
