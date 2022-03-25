//
// Created by GEORG on 01.12.2021.
//
#include "Vector.h"

Vector Vector::operator * (Vector c2)
{
    Vector c3;
    c3.x = y*c2.z - z*c2.y;
    c3.y = z*c2.x - x*c2.z;
    c3.z = x*c2.y - y*c2.x;

    return Vector(c3.x,c3.y,c3.z);

}

Vector Vector::operator + (Vector c2)
{
    //return Vector(x*c2.x + y*c2.y + z*c2.z)
    return Vector(x+c2.x, y+c2.y, z+c2.z);
}
Vector Vector::operator - (Vector c2)
{
    return Vector(x-c2.x, y-c2.y, z-c2.z);
}
double Vector::operator & (Vector c2)
{
    return (x*c2.x + y*c2.y + z*c2.z);
}


Vector :: Vector(double in1, double in2, double in3)
{
    x = in1;
    y = in2;
    z = in3;
    p = sqrt((double)x*(double)x + (double)y*(double)y + (double)z*(double)z);
    phi = atan((double)y / (double)x) * (double)180/3.14;
    teta = acos((double)z / sqrt((double)x*(double)x + (double)y*(double)y + (double)z*(double)z)) * (double)180/3.14;

}
Vector :: Vector()
{
}

void Vector :: display()
{
    std::cout << "(x,y,z) : " << x << ", " << y << ", " << z << ".\n";
    std::cout << "(p,teta,phi) : " << p << ", " << teta  << ", " << phi << ".\n";
}
