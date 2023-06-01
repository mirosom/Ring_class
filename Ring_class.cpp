#include <iostream>
#include "ring2.h"
int main() {
    ring2<std::string> textring(5);
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");
    textring.add("six");

    ring2<int> ints{1,2,3,42,23,-5};

    std::cout<<"with a for loop: \n";
    for (int i{0}; i< textring.size(); ++i) {
        std::cout<< "for: " <<textring.get(i) << '\n';
    }

    std::cout<<"\nWith C++98 style iterator: \n";
    for(ring2<std::string>::iterator it = textring.begin(); it!=textring.end(); ++it) {
        std::cout<<"iter: " << *it <<'\n';
    }

    std::cout<<"\nWith for range loop: \n";
    for(auto s : textring) {
        std::cout<<" for range: " << s <<'\n';
    }

    std::cout<<"\nPrinting a container constructed from an initalizer list: \n";
    for(auto i : ints) 
        std::cout<<"ini_list: "<<i<<'\n';
    return 0;
}