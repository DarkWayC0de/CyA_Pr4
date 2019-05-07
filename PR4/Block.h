//
// Created by DarkWayC0de_pc on 03/11/2018.
//

#ifndef PR4_BLOCK_H
#define PR4_BLOCK_H


#include <iostream>
namespace CyA {

    class Block{
    private:
        unsigned valor_;

    public:
        Block(unsigned a);
        ~Block(void){}
        std::ostream& write(std::ostream& os);

        unsigned& getset(void);
    };

}

#endif //PR4_BLOCK_H
