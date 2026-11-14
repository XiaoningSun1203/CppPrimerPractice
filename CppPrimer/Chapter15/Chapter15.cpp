#include <iostream>
#include <string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &bookNo, double sales_price) :\
            m_bookNo(bookNo), m_price(sales_price) { }
    
    std::string isbn() const {return m_bookNO;}
    //作用：输入书籍数量，返回销售总额，希望派生类改写
    virtual double net_price(std::size_t n) const {return n * m_price;}

    virtual ~Quote(){ }
private:
    std::string m_bookNO;
protected:
    double m_price = 0.0;
};

double print_total(ostream &os, const Quote &item, std::size_t n){
    double ans = item.net_price(n);
    os << "ISBN:" << item.isbn() << ",数量：" << n << ",总价:" << ans << endl;
    return ans;
}

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& bookNo, double price, std::size_t qty, double disc):Quote(bookNo, price), min_qty(qty), discount(disc) { }


    virtual double net_price(std::size_t n) const override {
        if (n > min_qty){
            return n * (1 - discount) * m_price;
        }
        else {
            return n * price;
        }
     }
private:
    std::size_t min_qty; //可享受折扣的最少数量
    double discount; // 折扣
};
int main(){
    Quote q;
    Bulk_quote b;
    print_total(std::cout, q, 48);
    print_total(std::cout, b, 48);

    return 0;
}
