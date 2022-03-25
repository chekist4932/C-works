//
// Created by GEORG on 01.12.2021.
//

#ifndef FIRST_VECTOR_H
#define FIRST_VECTOR_H


#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>



class Vector {
public:
    Vector(double , double, double);
    Vector();
    void display();

    //Complex operator + (Complex c2);
    Vector operator * (Vector c2);
    Vector operator + (Vector c2);
    Vector operator - (Vector c2);
    double operator & (Vector c2);

private:
    double x, y,z;
    double phi,p,teta;

};












#endif //FIRST_VECTOR_H
