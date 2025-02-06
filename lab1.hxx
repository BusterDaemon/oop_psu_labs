#ifndef _LAB1_HXX_
#define _LAB1_HXX_

#include <string>

class product {
    private:
        std::string name;
        std::string manufacturer;
        float price;
        int goden_do;
        int count;
    public:
        product();
        product(std::string name, std::string manuf, float pr, int goden, int count);
        product(product &p);
        ~product();
        void set_name(std::string name);
        std::string get_name();
        void set_manufacturer(std::string manuf);
        std::string get_manufacturer();
        void set_price(float price);
        float get_price();
        void set_goden(int goden);
        int get_goden();
        void set_count(int count);
        int get_count();
};

#endif