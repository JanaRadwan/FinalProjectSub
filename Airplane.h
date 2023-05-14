#include"Dequeue.cpp"

class Airplane {
private:
	int Tarrival;
	int Twait;

public:
	Airplane() {
		this->setTarrival(0);
		this->setTwait(0);
	}
	Airplane(int arrivalTime) {
		this->Tarrival = arrivalTime;
		this->Twait = 0;
	}

	void setTarrival(int x) { Tarrival = x; }
	void setTwait(int y) { Twait = y; }
	int getTarrival() { return Tarrival; }
	int getTwait() { return Twait; }

};




