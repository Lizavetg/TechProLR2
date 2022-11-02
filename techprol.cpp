#include <iostream>
#include <random>

using namespace std;

class range {
    public:
        float min;
        float max;
};

class sensors {
    public: 
        string name;
        string measurement_unit;
        // float measure_range_min;
        // float measure_range_max;
        range measurement_range; 

        void measure()
        {
            // cin >> measurement_range.min;
            // cout << endl;
            // cin >> measurement_range.max;
            random_device rd;
            mt19937 e2(rd());
            uniform_real_distribution<> dist(measurement_range.min, measurement_range.max);
            cout << dist(e2) << endl;

        }
};

class complex_navigation_system {
    public:
        string name;
        void add_sensor();
        float measure_acc();
        float measure_gyro();
        float measure_position();
        char list_sensors();
        sensors B[3];
};

int main ()
{
    complex_navigation_system A;
    A.B[0].name = "Acc";
    A.B[0].measurement_unit = "mV/g";
    A.B[0].measurement_range.min = 0;
    A.B[0].measurement_range.max = 2;
    A.B[0].measure();

    A.B[1].name = "Gyro";
    A.B[1].measurement_unit = "rad/s";
    A.B[1].measurement_range.min = 20;
    A.B[1].measurement_range.max = 40;
    A.B[1].measure();

    A.B[2].name = "Position";
    A.B[2].measurement_unit = "rad/s";
    A.B[2].measurement_range.min = 10;
    A.B[2].measurement_range.max = 15;
    A.B[2].measure();
}
