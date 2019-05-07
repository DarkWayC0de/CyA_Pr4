//
// Created by DarkWayC0de_pc on 03/11/2018.
//

#include "Block.h"

namespace CyA{
    Block::Block(unsigned a) :valor_(a) {

    }
    std::ostream& Block::write(std::ostream& os){

        for (int i = 0; i <valor_-1 ; ++i) {
            os << "x ";
        }
        os<<"x";
        return os;
    }

    unsigned& Block::getset() {
        return  valor_;
    }
}

