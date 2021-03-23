/*
Title : C++ Inheritance (Base and derived class)
Author : TutorialPoint
Link: https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
*/

//Dylan Nelson - X00144862
// couldnt quite get this question

#include <iostream>

//base class
class shape
{
public:
    void draw(int length,int width);
};

//derived classes below
class circle :public shape {
 
};

class triangle :public shape {

};

class square :public shape {

};

int main(void) {
    square s;
    triangle t;
    circle c;

    std::cout << "Shape is : ";
};

