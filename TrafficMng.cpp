#include <iostream>
#include<queue>
#include<string>
#include<fstream>
#include<ctime>
#include<vector>
#define HEADER "**********\t\t\t    **********\n\n\t   TRAFFIC MANAGEMENT SYSTEM\t   \n\n**********\t\t\t    **********\n\n"
using namespace std;

class Authorisation {
public:
    void auth() {
        int c;
        l1:cout << HEADER << "Authorise yourself to start simulation -\n" << "Menu :\n\n1.Register\n2.Login\n3.Exit\n" << endl;
        cout << "Enter choice : ";
        cin >> c;
        cout << endl;
        if (c == 1) {
            cout << "ENTER DETAILS TO REGISTER YOURSELF - " << endl << endl;
            string user, pass;
            lu:cout << "Enter username : ";
            cin >> user;
            ifstream ip("User_Database.txt", ios::in);
            string line;
            while(getline(ip, line)){
                if(line.find(user) != string::npos){
                    ip.close();
                    cout << "Username not available! Try Again!\n\n";
                    goto lu;
                }
            }
            ip.close();
            cout << "Enter password : ";
            cin >> pass;
            ofstream op("User_Database.txt", ios::app);
            op << user << " " << pass << endl;
            op.close();
            cout << "Registered Successfully!" << endl << endl;
            system("pause");
            system("cls");
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
                    ip.close();
                    return;
                }
            }
            ip.close();
            cout << "Login Unsuccessfull! Try Again!" << endl << endl;
            system("pause");
            system("cls");
            goto l1;
        }
        else if(c == 3){
            system("cls");
            cout << "Thanks You!\n";
            _Exit(10);
        }
        else {
            cout << "Enter a valid choice !" << endl;
            system("pause");
            system("cls");
            goto l1;
        }
    }
};

class vehicle {
    int id;
    int emergency;
    int speed;
    static int i;
public:
    vehicle(int e = 0) {
        id = i++;
        emergency = e;
        speed = 10 + rand() % 51;                //Vehicles with speed 10 - 60
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
int vehicle::i = 0;

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
public:
    string color;
    traffic_light() {
        color = "red";
    }
    void changeLight(string c) {
        color = c;
    }
};

class traffic_lane : public Input_sensor, public traffic_light {
public:
    queue<vehicle> qv;
    int laneNo;
    int speedLimit;
    int currentVehicles;
    int currentEV;
    traffic_lane(int ln, int sl) {          //lane number and speed limit
        currentVehicles = 0;
        currentEV = 0;
        speedLimit = sl;
        laneNo = ln;
    }
    int getCurrentVehicles() {
        return currentVehicles;
    }
    int getCurrentEV() {
        return currentEV;
    }
    void updateTraffic() {
        int* A = getTraffic();
        qv = queue<vehicle>();                  //To empty the queue
        for (int i = 0; i < A[1]; i++) {
            vehicle* nv = new vehicle(1);
            qv.push(*nv);                       //Push Emergency Vehicles
        }
        for (int i = 0; i < A[0]; i++) {
            vehicle* nv = new vehicle(0);
            qv.push(*nv);                       //Push Other Vehicles
        }
        currentVehicles = A[0];
        currentEV = A[1];
    }
    friend bool operator<(traffic_lane& l1,traffic_lane& l2);
};

bool operator <(const traffic_lane& l1, const traffic_lane& l2){
    if(l1.currentEV != l2.currentEV)
        return l1.currentEV < l2.currentEV;
    else
        return l1.currentVehicles < l2.currentVehicles;
}
class Outgoing {
    priority_queue<traffic_lane> pql;
public:
    Outgoing(traffic_lane l1, traffic_lane l2, traffic_lane l3, traffic_lane l4){
        pql.push(l1); pql.push(l2); pql.push(l3); pql.push(l4);
    }
    void startTraffic() {
        cout << "Started\n";
        while(!pql.empty()){
            traffic_lane cl = pql.top();
            pql.pop();
            cl.changeLight("Green");
            cout << "Lane " << cl.laneNo << " light turned " << cl.color << endl;
            cout << "Total Vehicles in Lane : " << cl.currentVehicles << " , Emergency Vehicles : " << cl.currentEV << endl;
            int vehToExit = 30;
            while(vehToExit>0 && cl.currentVehicles > 0){
                vehicle cv = cl.qv.front();
                if(cv.isEmergency()){
                    cl.qv.pop();
                    cl.currentVehicles--;
                    cl.currentEV--;
                }
                else{
                    if(cv.getSpeed() > cl.speedLimit){
                        ofstream of("OverSpeeding.txt", ios::app);
                        of << "E-challan for Vehicle with ID : " << cv.getId() << " for violating the speed limit in lane " << cl.laneNo << endl;
                        of.close();
                    }
                    cl.qv.pop();
                    cl.currentVehicles--;
                }
                vehToExit--;
            }
            cout << "Lane " << cl.laneNo << " vehicles started movement" << endl;
            cl.changeLight("Red");
            cout << "Lane " << cl.laneNo << " light turned " << cl.color << endl;
            cout << "Lane " << cl.laneNo << " vehicles remaining : " << cl.currentVehicles << " , Emergency Vehicles : " << cl.currentEV << endl << endl;
            system("pause");
            if(cl.currentVehicles > 0) pql.push(cl);
        }
    }
};

void printEChallan(){
    ifstream iff("OverSpeeding.txt");
    string s;
    cout << "Generated E-challans are : " << endl;
    while(getline(iff, s)){
        cout << s << endl;
    }
    cout << endl;
    iff.close();
}

int main() {
    Authorisation AU;
    aul:AU.auth();
    cout << "***********************************************" << endl << endl;
    system("pause");
    system("cls");

    srand(time(0));
    traffic_lane l1(1,40),l2(2,35),l3(3,40),l4(4,45);           //Lanes with respective speed limits

    while(1){
        system("cls");
        cout << HEADER;
        la:cout << "Menu :\n\n1.Update Traffic\n2.Start simulation\n3.Display Generated Challans\n4.Logout\n" << endl;
        cout << "Select option : ";
        int c; cin >> c;
        if(c==1){
            system("cls");
            cout << HEADER;
            cout << "Input Lane 1 data :\n";
            l1.updateTraffic();
            cout << "Input Lane 2 data :\n";
            l2.updateTraffic();
            cout << "Input Lane 3 data :\n";
            l3.updateTraffic();
            cout << "Input Lane 4 data :\n";
            l4.updateTraffic();
            system("pause");
        }
        else if(c==2){
            system("cls");
            cout << HEADER;
            Outgoing og(l1,l2,l3,l4);
            og.startTraffic();
            system("pause");
        }
        else if(c==3){
            system("cls");
            cout << HEADER;
            printEChallan();
            system("pause");
        }
        else if(c==4){
            system("cls");
            cout << "Logged Out Successfully!" << endl << endl;
            system("pause");
            system("cls");
            goto aul;
        }
        else{
            cout << "!! Select a valid option (1-3) !!" << endl << endl;
            system("pause");
            system("cls");
            cout << HEADER;
            goto la;
        }
    }
    return 0;
}
