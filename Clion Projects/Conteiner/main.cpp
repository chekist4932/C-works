#include <iostream>
#include<stdlib.h>
#include<time.h>


class contain
{
public:
    contain(int,int);
    contain(int);
    ~contain();
    void show();
    void max();
    void resize(int);
    void copy(contain);
    void test();
    void operator = (contain c2);

private:

    int* a;
    double * b;
    int n;
    int fl;
    int empty;
};

contain ::contain(int in1, int in2) {
    fl = in1;
    n = in2;
    empty = 0;
    if(fl == 0)
    {
        a = new int[n];
        b = 0;
        for(int i = 0; i< n;i++)
        {
            a[i] = rand() % in2;
        }
    }
    else if (fl == 1)
    {
        b = new double[n];
        a = 0;
        for(int i = 0; i< n;i++)
        {

            b[i] = (rand() % 1000 ) / (double)in2 ;
        }
    } else{
        std::cout << "Incorrect input.\n0 - int;\t1 - double\n";
    }
}
contain ::contain(int in1) {
    fl = in1;
    empty = 1;
    if(fl == 0)
    {
       a = 0;
    }
    else if(fl == 1)
    {
        b = 0;
    }
    else
    {
        std::cout << "Incorrect input.\n1 - int;\t2 - double\n";
    }

}
void contain ::resize(int in) {

    if(empty == 0)
    {
        if(fl == 0)
        {
            if(n > in)
            {
                int mp[in];
                for(int i = 0; i<in; i++)
                {
                    mp[i] = a[i];
                }
                if(a != 0)
                {//delete []b;
                    a = 0;}
                a = new int[in];
                for(int i = 0; i<in; i++)
                {
                    a[i] = mp[i];
                }
                n = in;
            } else if(n < in)
            {
                int mp[n];
                for(int i = 0; i<n; i++)
                {
                    mp[i] = a[i];
                }
                delete []a;
                a = new int[in];
                for(int i = 0; i<n; i++)
                {
                    a[i] = mp[i];
                }
                for(int i = n; i<in; i++)
                {
                    a[i] = rand() % in;
                }
                n = in;
            }

        }
        else if(fl == 1)
        {
            if(n > in) // уменьшение размерности
            {
                double mp[in];
                for(int i = 0; i<in; i++)
                {
                    mp[i] = b[i];
                }
                if(b != 0)
                {//delete []b;
                b = 0;}

                b = new double[in];
                for(int i = 0; i<in; i++)
                {
                    b[i] = mp[i];
                }
                n = in;
            } else if(n < in)
            {
                double mp[n];
                for(int i = 0; i<n; i++)
                {
                    mp[i] = b[i];
                }
                delete []b;
                b = new double[in];
                for(int i = 0; i<n; i++)
                {
                    b[i] = mp[i];
                }
                for(int i = n; i<in; i++)
                {
                    b[i] = (rand() % 1000 ) / (double)in ;
                }
                n = in;
            }

        }
    }
    else if(empty == 1)
    {
        empty = 0;
        n = in;
        if(fl == 0)
        {

            a = new int[n];
            for(int i = 0; i < n; i++)
            {
                a[i] = rand() % n;
            }

            /*for(int i = 0; i< in;i++)
            {
              std:: cout << a[i] << " ";
            }*/
        }
        else if(fl == 1)
        {
            b = new double[n];
            for(int i = 0; i< n;i++)
            {
                //std :: cout << rand() / (double)in2 << " ";
                b[i] = (rand() % 1000 ) / (double)n ;
            }


        }
    }


}

//void contain ::copy(contain c2)
void contain ::operator =  (contain c2){

    a = 0;
    b = 0;
    delete []a;
    delete []b;
    empty = 1;
    if (c2.fl == 0) // Присваеваемый массив - int
    {
        fl = 0;
    }
    else if (c2.fl == 1) // Присваеваемый массив - int
    {
        fl = 1;
    }
    if(c2.empty == 0)
    {
        std::cout << " + ";
        n = c2.n;
        if (c2.fl == 0) // Присваеваемый массив - int
        {
            a = new int [n];

            if (c2.fl == 0)
            {
                for(int i = 0; i < c2.n; i++)
                {
                    a[i] = c2.a[i];
                }
            }
            else
            {
                for(int i = 0; i < c2.n; i++)
                {
                    a[i] = (int)c2.b[i];


                }
            }
            empty = 0;
        }
        else if(c2.fl == 1) // Присваеваемый массив - double
        {
            b = new double [n];

            if (c2.fl == 0)
            {
                for(int i = 0; i < c2.n; i++)
                {
                    b[i] = (double) c2.a[i];

                }
            }
            else if(c2.fl == 1)
            {


                for(int i = 0; i < n; i++)
                {
                    b[i] = c2.b[i];

                }

            }
            empty = 0;
        }
    }











}
void contain :: test()
{
    std:: cout << n <<" +\n";
    for(int i = 0;i < n; i++)
    {
        std:: cout << b[i] << " ";
    }
}
 void contain::show() {
    if(empty == 0){
        if(fl == 0)
        {
            std :: cout << "Massive int:\n";
            for(int i = 0;i < n; i++)
            {
               std:: cout << a[i] << " ";
            }
            std::cout << "\n" << &a[0]  <<"\n";
        } else if(fl == 1)
        {
            std :: cout << "Massive double:\n";
            for(int i = 0;i < n; i++)
            {
                std:: cout << b[i] << " | ";
            }
            std::cout << "\n" << &b[0]  <<"\n";
        }
    } else if(empty == 1)
    {
        if(fl == 0)
        {
            std::cout << "Int container is empty.\n";
        } else if(fl == 1)
        {
            std::cout << "Double container is empty.\n";
        }
    }


}

void contain::max() {
    if(empty == 0)
    {
        int max_p = 0;
        int min_p = 0;
        if(fl == 0)
        {

            for(int i = 0; i < n; i++)
            {
                if(a[i] > a[max_p])
                {
                    max_p = i;
                }
                if(a[i] < a[min_p])
                {
                    min_p = i;
                }
            }
            std :: cout << "Max:\t"<< a[max_p] << "\tMin:\t" << a[min_p] <<"\n";
            std :: cout << "Address max:\t"<< &a[max_p] << "\tAddress min:\t" << &a[min_p] <<"\n";
        } else if(fl == 1)
        {

            for(int i = 0; i < n; i++)
            {
                if(b[i] > b[max_p])
                {
                    max_p = i;
                }
                if(b[i] < b[min_p])
                {
                    min_p = i;
                }
            }
            std :: cout << "Max:\t"<< b[max_p] << "\tMin:\t" << b[min_p] <<"\n";
            std :: cout << "Address max:\t"<< &b[max_p] << "\tAddress min:\t" << &b[min_p] <<"\n";
        }
    }
    else if(empty == 1)
    {
        if(fl == 0)
        {
           std::cout << "Int container is empty.\n";
        } else if(fl == 1)
        {
            std::cout << "Double container is empty.\n";
        }
    }
}



contain :: ~contain() {
    if(a!=0)
    {
        delete []a;
        a = 0;
    }
    if( b!= 0)
    {
        delete []b;
        b = 0;
    }

}




int main() {
    srand(time(0));
    contain one(0,14);

    contain two(1, 13 );
    one.show();
    two.show();

    std::cout << "GO\n";
    //one.copy(two);
    one = two;


    one.show();


    two.resize(8);
    two.show();

    one.show();

    two.max();


    //one.test();
    //contain one(1,10);
    //one.show();
    //one.max();
    //contain two(1);
    //two.show();
    //std::cout << "\tResize\n";
    //two.resize(100);
    //two.show();
    //two.max();
    //std::cout << "\tResize\n";
    //two.resize(10);
    //two.show();
    //std::cout << "\tResize\n";
    //two.resize(17);
    //two.show();
    return 0;
}
