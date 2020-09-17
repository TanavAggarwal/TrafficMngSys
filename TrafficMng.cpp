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
    int* A;
public:
    Input_sensor() {
        newTraffic = 0;
    };
    friend int* get_traffic();
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

class traffic_light {
    string color;
public:
    traffic_light() {
        color = "red";
    };
    void changeLight(string c) {
        color = c;
    };
};
struct lessthan{
    bool operator()(const vehicle& lhs, const vehicle& rhs)
    {
    return lhs.emergency <= rhs.emergency;
    }
}
class traffic_lane {
    int currentTraffic;
    int speedLimit;
    priority_queue<vehicle,vector<vehicle>, lessthan> pq;

public:
    friend class vehicle;
    traffic_lane(int sl) {
        currentTraffic = 0;
        speedLimit = sl;
    };
    void push_queue(){
      int* t= get_traffic();
      for(int i=0;i<t[0];i++){
          pq.push(vehicle());
      }
      for(int i=0;i<t[1];i++){
          pq.push(vehicle(1));
      }
    }
};

class Outgoing {

public:

};

int main() {

    return 0;
}
