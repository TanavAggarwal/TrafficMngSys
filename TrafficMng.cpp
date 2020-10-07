#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Authorisation {
    public:
    int auth(){
	label:
	string p,q,w;
	int x;
    string s;
	cin>>x;
	if(x==1){

			
  			ofstream fout;
  			cout<<"ENTER YOUR USERNAME"<<endl;
  			cin>>s;
  			cout<<"ENTER YOUR PASSWORD"<<endl;
  			cin>>p;
  			s=s+p;
  			ifstream fin;
  			string line;
  			int offset=0;
  			fin.open("myfile.txt");
  			if(fin.is_open())
  			{
  				while(!fin.eof())
  				{
  					getline(fin,line);
					if(line.find(s,0)!=-1)
					{
						cout<<"sorry! this username is not available"<<endl;
						cout<<"Press any key to go to Home Page"<<endl;
						char kk;
						cin>>kk;
						goto label;
						//break;
					}
				}
			}
  			fin.close();
  			fout.open("myfile.txt",ios::app);
  			fout<<s+"\n";
  			fout.close();
	}
		else if(x==2){

			string line;
			
  			ifstream fin;
  			int offset=0;
  			cout<<"ENTER YOUR USERNAME"<<endl;
  			cin>>q;
  			cout<<"ENTER YOUR PASSWORD"<<endl;
  			cin>>w;
  			q=q+w;
  			fin.open("myfile.txt");
  			if(fin.is_open())
  			{
  				while(!fin.eof())
  				{
  					getline(fin,line);
					if(line.find(q,0)!=-1)
					{
						cout<<"you are logged in"<<endl;
						offset=1;
						break;
						  }
				}
				if(offset==0)
				{
					cout<<"sorry you are unauthorised!!"<<endl;
					cout<<"Press 1 and enter to go to home page"<<endl;
					//getch();
					char o;
					cin>>o;
					goto label;
								  }
			}
  			fin.close();
	}
	else if(x==3){
		return 0;
	}else{
	    goto label;
	}
    return 0;
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
    cout << "** TRAFFIC MANAGEMENT SYSTEM **" << endl << endl;
    cout << "Authorise yourself to start simulation -" << endl;
    l1:cout << "Press 1 to register OR Press 2 to login : ";
    
    Authorisation AU;
    AU.auth();
    cout << "\n\n********************************\n\n";

    return 0;
}
