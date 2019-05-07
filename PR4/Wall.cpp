//
// Created by DarkWayC0de_pc on 05/11/2018.
//

#include "Wall.h"
namespace CyA{
     Wall::Wall(unsigned l, unsigned h, std::vector<unsigned> bloqs):L_(l),H_(h),Blqs_(bloqs){
        Row a(L_,Blqs_);
        a.generate_all(wall_);
    }
    Wall::Wall(unsigned l, unsigned h, std::vector<unsigned> bloqs,int a):L_(l),H_(h),Blqs_(bloqs){

    }
    Wall::~Wall() {

    }
    void Wall::generate_all(std::vector<CyA::Wall> &a) {
         if(H_<1){
             std::cout<<"ERROR, Altura muy pequena para el tamano del bloque";
         } else{
             std::vector<Row> b;
             for (int i = wall_.size()-1 ; i >=0; i--) {
                 b.clear();
                 b.push_back(wall_[i]);
                 int n=H_-1;
                 generate_all_r(a,b,n);
             }

        }
     }

     bool Wall::compare(CyA::Row a, CyA::Row b) {
         int x=a.getrow_(0).getset(),y=b.getrow_(0).getset();
         unsigned z=1,w=1;
         for (int i = 0;(x!=y); ++i) {
             if(x<=y){
                 x+=a.getrow_(z).getset();
                 z++;
             }else{
                 y+=b.getrow_(w).getset();
                 w++;
             }
         }
         return !(y!=L_||x!=L_);
     }
     void Wall::generate_all_r(std::vector<Wall>& a,std::vector<Row>& b ,int& c) {
         if(c!=0){
             for (int i = wall_.size()-1; i>=0 ; i--) {
                 if(compare(b[b.size()-1],wall_[i])){
                     b.push_back(wall_[i]);
                     c--;
                     generate_all_r(a,b,c);
                     b.pop_back();
                     c++;
                 }
             }
         }else{
             Wall d(L_,H_,Blqs_,0);
             d.insert_wall(b);
             a.push_back(d);

         }
     }
     void Wall::insert_wall(std::vector<CyA::Row> a) {
         wall_=a;
     }

     std::ostream& Wall::write(std::ostream &os) {

         for (int i = 0; i <L_*2+1; ++i) {
             os<<"#";
         }
         os<<std::endl;
         for (int j = 0; j <wall_.size() ; ++j) {
             wall_[j].write(os)<<std::endl;
         }
         for (int i = 0; i <(L_*2 +1); ++i) {
             os<<"#";
         }
         return os;
     }
}