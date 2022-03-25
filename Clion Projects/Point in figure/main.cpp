#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Vector.h"

class point
{
public:
    point(double,double);
    point();
    double& operator[] (const int index);

private:
    double po[2];

};
point::point(double in1, double in2) {
    po[0] = in1;
    po[1] = in2;
    //std::cout << po[0] << "  " << po[1] << "\n";
}
double& point::operator[] (const int index)
{
    return po[index];
}

point::point() {}



class ray
{
public:
    ray(double,double,double);
    ray();
    double& operator[] (const int index);

private:
    double poli[3];

};
ray :: ray(double in1,double in2,double in3)
{
    poli[0] = in1;
    poli[1] = in2;
    poli[2] = in3;
}

ray :: ray(){}

double& ray::operator[] (const int index)
{
    return poli[index];
}

int main2()
{
    double b;
    std::cin >> b;
    std::cout << b;
}





int main() {
    double x = 0;
    double y = 0;
    int np = 5;

    point* points = new point[np];
    ray* list = new ray [10];

    std:: cout << "Input points IN CORRECT WAY: \n";

    for(int i = 0; i < np; i++)
    {
        if (i != np - 1)
        {
            std :: cout << "Point " << i << " (x y): \n";
        }
        else
        {
            std :: cout << "Point for check (x y): \n";
        }
        std :: cin >> x >> y;
        points[i] = point(x,y);
        //int t= 0;
        //std::cin >> t;

    }
    std:: cout << "\nReceived data: \n";
    for(int i = 0; i< np;i++)
    {
        std:: cout << points[i][0] << " " << points[i][1] << "\n" ;
    }

    for(int i = 0; i < np; i++)
    {
        if (i < np - 2)
        {
            //std :: cout << "+\n";
            list[i] = ray(points[i+1][1] - points[i][1], points[i+1][0] - points[i][0],
                          -(points[i][1]*(points[i+1][0] -
                                          points[i][0]) ) + points[i][0]*(points[i+1][1] - points[i][1])) ;
        }
        else if (i == np - 2)
        {
            // :: cout << "-\n";
            list[i] = ray(points[0][1] - points[i][1], points[0][0] - points[i][0],
                          -(points[i][1]*(points[0][0] -
                                          points[i][0]) ) + points[i][0]*(points[0][1] - points[i][1])) ;
        }
        else
        {
            list[i] = ray(0,10,-(points[i][1] * (10)));
        }
    }
    std::cout << "\n";
    for(int i = 0; i < np ; i++)
    {
        std :: cout << "For"<< i  <<" line X: " << list[i][0] << " Y: " << list[i][1] << " K: " << list[i][2] << "\n";
    }
    std::cout << "\n";

    double ** pop = new double *[np-1];
    for(int i = 0;i<np-1;i++)
    {
        pop[i] = new double [2];
    }

    double* line_points_X = new double [np-1];
    double* line_points_Y = new double [np-1];

    double mp_x = 0;
    double mp_y = 0;
    double mp_k = 0;

    // Точки пересечения прямых с проведеным лучом
    std::cout << "Control points:\n";
    for(int i = 0; i<np-1;i++)
    {
        if(list[i][0] != 0 && list[i][1] != 0 && i != np-1)
        {
            mp_y = -list[np-1][0]*(list[i][1]/list[i][0]) + list[np-1][1];
            mp_k = -list[np-1][0]*(list[i][2]/list[i][0]) + list[np-1][2];
            line_points_Y[i] = -mp_k/mp_y;
            line_points_X[i] = (list[i][1] * line_points_Y[i] + list[i][2]) / list[i][0];
            std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\n";
        } else if( list[i][0] == 0 && list[i][1] != list[np-1][1])
        {
            line_points_Y[i] = 666.314;
            line_points_X[i] = 666.314;
            std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\n";
            //line_points_Y[i] = -list[i][2] / list[i][1];
            //line_points_X[i] = (list[np-1][1] * line_points_Y[i] + list[np-1][2]) /
        } else if(list[i][1] == 0)
        {
            line_points_X[i] = list[i][2] / list[i][0];
            line_points_Y[i] = -list[np-1][2]/ list[np-1][1];
            std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\n";
        }

    }

    double max_X = 0;
    double min_X = 0;
    double max_Y = 0;
    double min_Y = 0;

    int count_location = 0;
    // Проверка принадлежности ТОЧЕК РЕБРАМ
    std::cout << "\nVerification of affiliation:\n";
    for(int i = 0; i< np-1; i++)
    {
        // для точек лежащих на ребрах, паралельных проведенной прямой
        if(line_points_Y[i] == 666.314 and line_points_X[i] == 666.314)
        {
            std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\t-\tOut figure.\n";
        }
        else{
            // ДЛЯ 1-3 РЕБРА
            if(i < np-2)
            {
                // MAX и MIN для X
                if(points[i][0] >= points[i+1][0]){
                    max_X = points[i][0];
                    min_X = points[i+1][0];
                }
                else
                {
                    min_X = points[i][0];
                    max_X = points[i+1][0];
                }
                // MAX и MIN для Y
                if(points[i][1] >= points[i+1][1]){
                    max_Y = points[i][1];
                    min_Y = points[i+1][1];
                }
                else
                {
                    min_Y = points[i][1];
                    max_Y = points[i+1][1];
                }
                // ПРОВЕРКА НА ПРИНАДЛЕЖНОСТЬ ТОЧКИ РЕБРУ
                if( (line_points_X[i] > min_X && line_points_X[i] < max_X) &&
                    (line_points_Y[i] > min_Y && line_points_Y[i] < max_Y) )
                {
                    std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\t-\tOn figure.\n";
                    pop[count_location][0] = line_points_X[i];
                    pop[count_location][1] = line_points_Y[i];
                    count_location++;
                } else
                {
                    std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\t-\tOut figure.\n";
                }
            }
            // ДЛЯ ПОСЛЕДНЕГО РЕБРА
            else{
                if(points[i][0] >= points[0][0]){
                    max_X = points[i][0];
                    min_X = points[0][0];
                }
                else
                {
                    // MAX и MIN для X
                    min_X = points[i][0];
                    max_X = points[0][0];
                }
                if(points[i][1] >= points[0][1]){
                    max_Y = points[i][1];
                    min_Y = points[0][1];
                }
                else
                {
                    // MAX и MIN для Y
                    min_Y = points[i][1];
                    max_Y = points[0][1];
                }
                // ПРОВЕРКА НА ПРИНАДЛЕЖНОСТЬ ТОЧКИ РЕБРУ
                if( (line_points_X[i] > min_X && line_points_X[i] < max_X) &&
                    (line_points_Y[i] > min_Y && line_points_Y[i] < max_Y) )
                {
                    std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\t-\tOn figure.\n";
                    pop[count_location][0] = line_points_X[i];
                    pop[count_location][1] = line_points_Y[i];
                    count_location++;
                } else
                {
                    std::cout << "X - " << line_points_X[i] << " Y - " << line_points_Y[i] << "\t-\tOut figure.\n";
                }
            }
        }

    }
    int count = 0;
    Vector p1p2(10,0, 0);
    double check = 0;
    //std:: cout << "\n Skalyar: " << check << "\n";
    // ПРОВЕРКА ПРИНАДЛЕЖНОСТИ ТОЧЕК ЛУЧУ
    std::cout << "\nVerification of points belonging to the RAY:\n";
    for(int i = 0; i < count_location;i++)
    {
        std:: cout << "\n Skalyar: " << "\n";
        Vector p1m(    pop[i][0] - points[np-1][0],   pop[i][1] - points[np-1][1],    0);
        check = p1p2 & p1m;
        //std:: cout << "\n Skalyar: " << check << "\n";
       if (check >= 0)
       {
           std::cout << "X: " << pop[i][0] << " Y: " << pop[i][1] << "\t-\tYES\n";
           count++;
       } else{
           std::cout << "X: " << pop[i][0] << " Y: " << pop[i][1] << "\t-\tNO\n";
       }
    }


    if(count % 2 == 1)
    {
        std::cout << "\nPOINT:\tX: " << points[np-1][0] << " Y: " << points[np-1][1] << " INSIDE FIGURE\n";
    }
    else
    {
        std::cout << "\nPOINT:\tX: " << points[np-1][0] << " Y: " << points[np-1][1] << " OUTSIDE FIGURE\n";
    }



    for(int i = 0;i<np-1;i++)
    {
        delete [] pop[i];
    }
    delete [] list;
    delete [] line_points_X;
    delete [] line_points_Y;
    delete [] points;
    return 0;
}


