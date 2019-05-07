//
// Created by DarkWayC0de_pc on 05/11/2018.
//

#ifndef PR4_WALL_H
#define PR4_WALL_H

#include "Row.h"

namespace CyA {

    class Wall {
        private:
            std::vector<Row> wall_;
            unsigned L_;
            unsigned H_;
            std::vector<unsigned> Blqs_;
            void generate_all_r(std::vector<Wall>& a,std::vector<Row>& b, int& c);
            void insert_wall(std::vector<Row> a);
            bool compare(Row a, Row b);

        public:
            Wall (unsigned  l, unsigned h, std::vector<unsigned> bloqs);
            Wall (unsigned l, unsigned h, std::vector<unsigned> bloqs,int a);
            ~Wall(void);
            void generate_all(std::vector<Wall>& a);
            std::ostream& write(std::ostream& os);
    };

}
#endif //PR4_WALL_H
