#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[][M])
{
    // Display top border
    for (int i = 0; i < M + 2; ++i) {
        cout << '-';
    }
    cout << endl;

    // Display image with left and right borders
    for (int i = 0; i < N; ++i) {
        cout << '|';  // Left border
        for (int j = 0; j < M; ++j) {
            cout << (image[i][j] ? '*' : ' ');
        }
        cout << '|' << endl;  // Right border
    }

    // Display bottom border
    for (int i = 0; i < M + 2; ++i) {
        cout << '-';
    }
    cout << endl;
}

void updateImage(bool image[][M], int brushSize, int x, int y)
{
    // Update the image based on the brush size and location
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            double distance = sqrt(pow(i - x, 2) + pow(j - y, 2));
            if (distance <= brushSize - 1) {
                image[i][j] = true;
            }
        }
    }
}