 #include <iostream>
 int main(){
    std::cout << "default bool values:" << true << false;
    std::cout << "\nalpha bool values:" << std::boolalpha 
              << true << false << std::noboolalpha << std::endl;
    std::cout << "default bool values:" << true << false;
    return 0;
 }
