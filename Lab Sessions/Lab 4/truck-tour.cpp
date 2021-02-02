#include <bits/stdc++.h>
using namespace std;

int truckTour(vector<vector<int>> petrolpumps) {

    int stations = petrolpumps.size();
    int start = -1; //initializing a random variable to store the start.

    for(int i = 0; i< stations;i++){
      if(start != -1) break; // If we have found a start no need of going further.
      else{
      //Determining a possible staring point. By considering station's fuel and
      //distance to the next station.
      // if fuel < distance for current station. skip to the next.
      if(petrolpumps[i][0] < petrolpumps[i][1]) continue;
      else{
        //Initiate the travel. Assuming station as a possible start.
        start = i;
        int current_station = i;
        int fuel = petrolpumps[current_station%3][0];
        int dist_to_next = petrolpumps[current_station%3][1];
        while(fuel >= dist_to_next){// to not to stuck in the middle of two stations
          current_station++;
          fuel = (fuel-dist_to_next) +petrolpumps[current_station%3][0];
          dist_to_next = petrolpumps[current_station%3][1];
          if((fuel == dist_to_next) && ((current_station+1)%3 == start)) break;
        }
      }
    }
    }
return start;
}

def truckTour(PP):
    n=len(PP)
    key =-1
    for i in range(n):
        start=False
        if key !=-1:
            break
        elif PP[i][0]>=PP[i][1]:
            fuel = PP[i][0]
            dis = PP[i][1]
            for j in range(i+1-n,i,1):

                if fuel < dis:
                    start = False
                    break

                else:
                    fuel=fuel+PP[j][0]-dis
                    dis=PP[j][1]
                    start=True
            if start==True:
                key=i
                break
        else:
            continue
    return key
