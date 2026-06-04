#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Star
{
    float x;
    float y;

    float vx;
    float vy;

};

int main()
{
    vector<Star> stars;

    for(int i = 0; i < 5; i++)
    {
        Star s;

        s.x = rand() % 500;
        s.y = rand() % 500;

        s.vx = i+1;
        s.vy = (i+1)*0.5;

        stars.push_back(s);
    }

    float blackHoleX = 250;
    float blackHoleY = 250;

    for(int step = 0; step < 3; step++)
    {
        cout << "Step " << step << endl;

        for(int i = 0; i < stars.size(); i++)
        {
            stars[i].x += stars[i].vx;
            stars[i].y += stars[i].vy;

            float dx=blackHoleX-stars[i].x;
            float dy=blackHoleY-stars[i].y;

            float distance = sqrt(dx * dx + dy * dy);

            float gravityStrength=50/distance;
            stars[i].vx+=gravityStrength*dx/distance;
            stars[i].vy+=gravityStrength*dy/distance;
            cout << "("
                 << stars[i].x
                 << ", "
                 << stars[i].y
                 << ") vx=" << stars[i].vx
                <<"vy= "
                <<stars[i].vy
                <<endl;
        }

        cout << endl;
    }

    return 0;
}