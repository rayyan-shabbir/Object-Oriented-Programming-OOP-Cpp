#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int num, guess;
    int attempt = 1;
    srand(time(NULL));
    num = rand()%100;

    do{
        cout << "Enter guess Number: ";
        cin >> guess;

        if(num < guess) {
            cout << "Guess lower number please" << endl;
        } else if(num > guess) {
            cout << "Guess higher number please" << endl;
        } else {
            cout << "You guessed it in " << attempt << " attempts";
        }

        attempt++;

    } while(num != guess);
    return 0;
}