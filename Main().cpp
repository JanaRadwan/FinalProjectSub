#include "Runway.h"
#include <cstdlib> 
#include <ctime>


int main() {
    int Tmax = 360;
    int DeltaT = 6;
    double pa = 1.0 / DeltaT;
    int t = 0, Tr = 0;
    int TotalwaitTime = 0;
    int num_planes_landed = 0;

    Deque<Airplane> LandingQueue;
    AirportRunway Runway;

    Runway.setTlanding(10);
    int n = 0; // number of arrivals

    srand(time(NULL));

    while (t < Tmax) {
        Airplane plane;
        float R = rand() / float(32767);

        if (R < pa ) 
        {  
            if (LandingQueue.isFull())
                cout << "Error:  Waiting line is full" << endl;
            else {
                plane.setTarrival(t);
                plane.setTwait(0);
                LandingQueue.insertRear(plane);
                cout << " Airplane arrived at time " << t << endl;
            }
        }
        if (Tr==0 && !LandingQueue.isEmpty()) { 
            plane = LandingQueue.getFront();
            Tr = Runway.getTlanding();
            plane.setTwait(t - plane.getTarrival());
            TotalwaitTime += plane.getTwait();
            LandingQueue.deleteFront();
            Runway.set_airplane(&plane);
            Runway.SetOccupy(true);

            num_planes_landed++;
            cout << "Arrival :" << n << " Airplane landed at time " << t << " with wait time " << plane.getTwait() << endl;
            

        }
        if (Tr > 0) {
            Tr--;
        }
        t++;n++;
    }
    double averageWaitTime = (double)TotalwaitTime / num_planes_landed;
    cout << " Number of Airplanes landed :" << num_planes_landed << endl;
    cout << " total wait time : " << TotalwaitTime << endl;
    cout << " Average wait time: " << averageWaitTime << endl;
    return 0;
}
