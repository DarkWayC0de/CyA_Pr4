#include <iostream>
#include "Block.h"
#include "Row.h"
#include "Wall.h"
#include <ctime>

int main() {
    unsigned a=0,z,t0,t1;
    std::vector <unsigned> b;
    while(a!=4294967295) {
        std::cout << "Introduce los tamanos separados por un enter, para terminar introduce -1:";
        std::cin>>a;
            b.push_back(a);
    }
    b.pop_back();
    std::cout<<"Introduce la longitud del muro:";
    std::cin>>a;
    std::cout<<"Introduce la altura del muro:";
    std::cin>>z;
    t0=clock();
    CyA::Wall A(a,z,b);
    std::vector<CyA::Wall> Walls_;
    A.generate_all(Walls_);




    t1=clock();
    double time=(double(t1-t0)/CLOCKS_PER_SEC);
    int h=0,m=0;
    m=time/60;
    time-=(m*60);
    h=m/60;
    m-=(h*60);
    std::cout<< "\nTiempo de computo: " <<h<<"h "<<m<<"m "<<time<<"s"<< std::endl;
    std::cout<<"\n Se han obtenido "<<Walls_.size()<<" muros, van del numero 1 al "<<Walls_.size();
    while(a!=4294967295){
        std::cout << "\nIntroduce el numero del muro que quieres ver,-2 para ver todos los muros -1 salir: ";
        std::cin>>a;
        if(a==4294967295){
            break;
        }
        if (a==4294967294){
            for (int i = 0; i <Walls_.size() ; ++i) {
                std::cout<<"\nMuro "<<i+1<<"º\n";
                Walls_[i].write(std::cout);
                std::cout<<std::endl;
            }
        }
        if((a!=4294967294)&&(a!=4294967295)) {
            std::cout << "\nMuro " << a << "º\n";
            Walls_[a - 1].write(std::cout);
            std::cout << std::endl;
        }
    }
    return 0;
}