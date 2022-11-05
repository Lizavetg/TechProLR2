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

        float measure()
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

        float measure_acc()
        {
             int i = 0;
            float value;
            B[i].measurement_range.min = 10;
            B[i].measurement_range.max = 30;
            return (float)B[i].measure();
        };

        float measure_gyro() 
        {
            int i = 0;
            B[i].measurement_range.min = 100;
            B[i].measurement_range.max = 120; 
            return (float)B[i].measure();
        };

        float measure_position() {
            int i = 0;
            B[i].measurement_range.min = 1;
            B[i].measurement_range.max = 5;
            return (float)B[i].measure();
        };

        void list_sensors() 
        {
             for (int i = 0; i < 3; i++) {
                cout << B[i].name << " ";
            }
            cout << endl;
        };

        void sensor_measurement_list() {
            for (int i = 0; i < 3; i++) {
                if (B[i].name == "Acc") {
                    measure_acc();
                }
                else if (B[i].name == "Gyro") {
                    measure_gyro();
                }
                else if (B[i].name == "Position") {
                    measure_position();
                }
            }
        }
};

int main ()
{
    complex_navigation_system A;
    
    A.add_sensor();
    cout << endl;
    A.list_sensors();
    A.sensor_measurement_list();
}
