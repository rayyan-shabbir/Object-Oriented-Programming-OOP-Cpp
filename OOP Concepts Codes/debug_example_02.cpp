#include "iostream"
using namespace std;

float calculateAvg(float sum, int n) {
    return sum / n;
}

int main() {
    // int n = 10;
    int n;
    cin >> n;

    float avg = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += i;

        avg = calculateAvg(sum, i);
    }

    cout << "AVERAGE: " << avg << endl;

    return 0;
}