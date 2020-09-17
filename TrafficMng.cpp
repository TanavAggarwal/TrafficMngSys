#include <iostream>
#include<queue>
using namespace std;

class Authorisation {
    
public :

};

class Alerts {

public:

};

class pedestrian_crossing {

public:

};

class vehicle {
    int id;
    int emergency;
    int speed;
    static int count;
public:
    vehicle(int e = 0) {
        id = count++;
        emergency = e;
        speed = rand() % 61;
    };
    int getId() {
        return id;
    };
    bool isEmergency() {
        return emergency ? true : false;
    };
    int getSpeed() {
        return speed;
    };
}; 

class Input_sensor {
    int newTraffic;
public:
    Input_sensor() {
        newTraffic = 0;
    };
    int* get_traffic() {
        int tv, ev;
        cout << "Total new vehicles : ";
        cin >> tv;
        cout << "Emergency vehicles : ";
        cin >> ev;
        int* A = new int[2];
        A[0] = tv; A[1] = ev;
        return A;
    };
}; 

class traffic_light {
    string color;
public:
    traffic_light() {
        color = "red";
    };
    void changeLigth(string c) {
        color = c;
    };
};

class traffic_lane {
    int currentTraffic;
    int speedLimit;
    priority_queue<vehicle> Ql;
public:
    traffic_lane(int sl) {
        currentTraffic = 0;
        speedLimit = sl;
    };

};

class Outgoing {

public:

};

int main() {

    return 0;
}
