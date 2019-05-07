//
// Created by DarkWayC0de_pc on 03/11/2018.
//

#include "Row.h"


namespace CyA{

    Row::Row(unsigned sz, std::vector<unsigned> a):sz_row_(sz){
        for (unsigned i = 0; i <a.size() ; ++i) {
            inset_blq(a[i]);
        }

    }
    std::ostream& Row::write(std::ostream &os) {
        os<<"|";
        for (unsigned i = 0; i <row_.size(); ++i) {
         row_[i].write(os);
         if(i!=row_.size()-1)
         os<<"|";
        }
        os<<"|";
        return os;
    }



    void Row::inset_blq(unsigned a) {
        sz_blqs_.push_back(a);
    }
   void Row::generate_all(std::vector<Row>& a) {
        if(sz_row_<sz_blqs_[0]){
            std::cout<<"ERROR, fila muy pequena para el tamano del bloque";
        } else{
            for (int i =sz_blqs_.size()-1;i>=0; i--) {
                row_.clear();
                if (sz_blqs_[i] <= sz_row_) {
                    Block b(sz_blqs_[i]);
                    row_.push_back(b);
                    generate_all_r( a,sz_row_ - sz_blqs_[i]);
                }
            }
        }
    }
    void Row::generate_all_r(std::vector<Row>& a, unsigned sz){
        if(sz!=0){
            for (int i =sz_blqs_.size()-1;i>=0; i--){
                if(sz_blqs_[i]<=sz && ((sz-sz_blqs_[i]>=sz_blqs_[0])||sz-sz_blqs_[i]==0)){
                    Block b(sz_blqs_[i]);
                    row_.push_back(b);
                    generate_all_r(a, sz - sz_blqs_[i]);
                    row_.pop_back();
                }
             }
        } else{
            Row b(sz_row_,sz_blqs_);
            b.insert_row(row_);
            a.push_back(b);
        }
    }
    void Row::insert_row(std::vector<Block> a){
        row_=a;
    }
    Block& Row::getrow_(unsigned a) {
        return row_[a];
    }

}