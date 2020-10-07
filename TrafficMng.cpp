#include <iostream>
#include<queue>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Authorisation {
public:
    void auth() {
        int c;
        l1:cout << "Enter 1 to register / 2 to login : ";
        cin >> c;
        cout << endl;
        if (c == 1) {
            ofstream op("User_Database.txt", ios::app);
            cout << "ENTER DETAILS TO REGISTER YOURSELF - " << endl;
            string user, pass;
            cout << "Enter username : ";
            cin >> user;
            cout << "Enter password : ";
            cin >> pass;
            op << user << " " << pass << endl;
            op.close();
            cout << "Registered Successfully!" << endl << endl;
            goto l1;
        }
        else if (c == 2) {
            cout << "ENTER DETAILS TO LOGIN - " << endl;
            string user, pass, uf, pf;
            cout << "Enter username : ";
            cin >> user;
            cout << "Enter password : ";
            cin >> pass;
            ifstream ip("User_Database.txt");
            while (ip >> uf >> pf) {
                if (uf == user && pf == pass) {
                    cout << "\nWelcome " << user << ", Login Successfull!" << endl << endl;
                    return;
                }
            }
            cout << "Login Unsuccessfull! Try Again!" << endl << endl;
            goto l1;
        }
        else {
            cout << "Enter a valid choice !" << endl;
            goto l1;
        }
    }
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
    cout << "**********                         **********" << endl << endl;
    cout << "          TRAFFIC MANAGEMENT SYSTEM          " << endl << endl;
    cout << "**********                         **********" << endl << endl;
    cout << "Authorise yourself to start simulation -" << endl;
    Authorisation AU;
    AU.auth();
    cout << "***********************************************" << endl;
    system("pause");
    system("cls");

    
    return 0;
}
