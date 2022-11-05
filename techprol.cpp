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
        range measurement_range; 

        void measure()
        {
            random_device rd;
            mt19937 e2(rd());
            uniform_real_distribution <> dist(measurement_range.min, measurement_range.max);
            cout << dist(e2) << " ";
            return dist(e2);
        }
};

class complex_navigation_system {
    public:
        string name;
         sensors B[3];
        void add_sensor()
            {
            for (int i = 0; i < 3; i++) {
                cout << "Enter the name of the sensor: ";
                cin >> B[i].name;
                cout << "Enter the unit of measurement: ";
                cin >> B[i].measurement_unit;
            }
        };
        float measure_acc(){
             int i = 0;
            float value;
            B[i].measurement_range.min = 10;
            B[i].measurement_range.max = 30;
            return (float)B[i].measure();
        };
        float measure_gyro();
        float measure_position();
        char list_sensors(){
             for (int i = 0; i < 3; i++) {
                cout << B[i].name << " ";
            }
            cout << endl;
        };
     
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
