#include <iostream>
#include "fstream"
using namespace std;

int main() {
    ofstream outf;
    outf.open("test1.txt");
    outf << "Hello World!";
    outf.close();
    return 0;
}