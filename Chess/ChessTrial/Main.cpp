#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Matrix* ptr = new ChessBoard;
    ptr -> print();

    delete ptr;
    
    return 0;
}