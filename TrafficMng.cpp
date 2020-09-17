#include <iostream>
#include<queue>
using namespace std;

class Authorisation {

public:

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
    }
    int getId() {
        return id;
    }
    bool isEmergency() {
        return emergency ? true : false;
    }
    int getSpeed() {
        return speed;
    }
};

class Input_sensor {
    int* A;
public:
    Input_sensor() {
        A = new int[2];
    }
    int* getTraffic() {
        int tv, ev;
        cout << "Total new vehicles : ";
        cin >> tv;
        cout << "Emergency vehicles : ";
        cin >> ev;
        A[0] = tv; A[1] = ev;
        return A;
    }
};

class traffic_light {
    string color;
public:
    traffic_light() {
        color = "red";
    }
    void changeLight(string c) {
        color = c;
    }
};

class traffic_lane : public Input_sensor{
    int currentVehicles;
    int currentEV;
    int speedLimit;
    queue<vehicle> qv;
public:
    traffic_lane(int sl) {
        currentVehicles = 0;
        currentEV = 0;
        speedLimit = sl;
    }
    int getCurrentVehicles() {
        return currentVehicles;
    }
    int getCurrentEV() {
        return currentEV;
    }
    void updateTraffic() {
        int* A = getTraffic();
        for (int i = 0; i < A[1]; i++) {
            vehicle* nv = new vehicle(1);
            qv.push(*nv);
        }
        for (int i = 0; i < A[0]; i++) {
            vehicle* nv = new vehicle(0);
            qv.push(*nv);
        }
        currentVehicles = A[0];
        currentEV = A[1];
    }
   
};

bool operator <(traffic_lane& l1,traffic_lane& l2){
    if (l1.getCurrentEV() == l2.getCurrentEV()) {
        return l1.getCurrentVehicles() < l2.getCurrentVehicles();
    }
    return l1.getCurrentEV() < l2.getCurrentEV();
   
}
class Outgoing {
    priority_queue<traffic_lane> pql;
public:

};

int main() {

    return 0;
}
