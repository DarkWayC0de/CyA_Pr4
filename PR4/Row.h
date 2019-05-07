//
// Created by DarkWayC0de_pc on 03/11/2018.
//

#ifndef PR4_ROW_H
#define PR4_ROW_H

#include <vector>
#include "Block.h"


namespace CyA{
    class Row {
    private:
        unsigned sz_row_;
        std::vector<Block> row_;
        std::vector<unsigned >sz_blqs_;


        void insert_row(std::vector<Block> a);
        void inset_blq(unsigned a);
        void generate_all_r(std::vector<Row>& a, unsigned sz);

    public:

        Row(unsigned sz, std::vector<unsigned> a );
        ~Row(void){}

        std::ostream& write(std::ostream& os);

        void generate_all(std::vector<Row>& a);

        Block& getrow_(unsigned);

    };

}

#endif //PR4_ROW_H



