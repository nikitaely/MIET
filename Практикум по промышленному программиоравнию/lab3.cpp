#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
constexpr auto SIZE = 16;

const std::string points[SIZE] = { "msk_AP","msk_TS","msk_WH","mzh_TS",
"mzh_WH","zvn_WH","NN_AP","NN_TS", "NN_WH","dzr_TS","dzr_WH",
"vlg_AP","vlg_TS","vlg_WH","kam_TS","kam_WH" };

const std::map<std::string, int> towns = {
	{"Moscow", 2},
	{"Mozhaisk", 4},
	{"Zvenigorod", 5},
	{"Nizhniy Novgorod", 8},
	{"Dzerzhinsk", 10},
	{"Volgograd", 13},
	{"Kamishin", 15} };

const std::map<std::string, int> table = {
	{"msk", 0},
	{"mzh", 1},
	{"zvn", 2},
	{"NN", 3},
	{"dzr", 4},
	{"vlg", 5},
	{"kam", 6} };

const std::tuple<int, int, double> tableCost[21] = {
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{0, 0, 0},
	{100, 60, 50},
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50},
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50} };

const int matrixDist[SIZE][SIZE] = {
{0, 20, 30, 108, 110, 65, 398, 0, 0, 0, 0, 926, 0, 0, 0, 0},
{20, 0, 10, 98, 100, 55, 0, 415, 0, 483, 0, 0, 937, 0, 1204, 0},
{30, 10, 0, 108, 110, 65, 0, 0, 430, 0, 390, 0, 0, 652, 0, 1234},
{108, 98, 108, 0, 5, 0, 0, 0, 0, 581, 0, 0, 1035, 0, 1302, 0},
{110, 100, 110, 5, 0, 78, 0, 0, 540, 0, 500, 0, 0 ,1062, 0, 1344},
{65, 55, 65, 0, 78, 0, 0, 0, 495, 0, 455, 0, 0, 1017, 0, 1299},
{398, 0, 0, 0, 0, 0, 0, 19, 23, 0, 26, 828, 0, 0, 0, 0},
{0, 415, 0, 0, 0, 0 ,19, 0, 4, 32, 0, 0, 840, 0, 919, 0},
{0, 0, 430, 0, 540, 495, 23, 4, 0, 0, 40, 0, 0, 849, 0, 1010},
{0, 483, 0, 581, 0, 0, 0, 32, 0, 0, 4, 0, 872, 0, 951, 0},
{0, 0, 390, 0, 500, 455, 26, 0, 40, 4, 0, 0, 0, 889, 0, 1050},
{926, 0, 0, 0, 0 ,0 ,828, 0, 0 ,0 ,0, 0, 15, 16, 0, 285},
{0, 937, 0, 1035, 0, 0, 0, 840, 0, 872, 0, 15, 0, 2, 257, 281},
{0, 0, 952, 0, 1062, 1017, 0, 0, 849, 0, 889, 16, 2, 0, 0 ,282},
{0, 1204, 0, 1302, 0, 0, 0, 919, 0, 951, 0, 0, 257, 0, 0, 2},
{0, 0, 1234, 0, 1344, 1299, 0, 0, 1010, 0, 1050, 285, 281, 282, 2, 0} };


enum Type { Turbo, Standart, Economy };

class Transport
{
protected:
	int speed;
	int volume;
	double price;
	int distance;

public:
	Transport();
	Transport(std::tuple<int, int, double>, int);
	virtual ~Transport();
	double sumCost(int mass, int dist);
	double sumTime(int dist);
	int getDistance();
};

Transport::Transport()
{
	price = 0;
	speed = 0;
	volume = 0;
	distance = 0;
}

Transport::Transport(std::tuple<int, int, double> tuple, int dist)
{
	price = std::get<0>(tuple);
	speed = std::get<1>(tuple);
	volume = std::get<2>(tuple);
	distance = dist;
}

Transport::~Transport()
{
}

double Transport::sumCost(int mass, int dist)
{
	return (mass / volume) * sumTime(dist) * price;
}

double Transport::sumTime(int dist)
{
	return dist / speed;
}

int Transport::getDistance()
{
	return distance;
}

class Train : public Transport
{
public:
	Train();
	Train(std::tuple<int, int, double> tuple, int dist);
};

Train::Train() : Transport()
{
	price = 200;
	speed = 100;
	volume = 500;
}

Train::Train(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist)
{
}

Train::Train(std::tuple<int, int, double> tuple, int dist)
{
	this->trainPrice = std::get<0>(tuple);
	this->trainSpeed = std::get<1>(tuple);
	this->trainVolume = std::get<2>(tuple);
	this->distance = dist;
}

class Car : public Transport
{
public:
	Car();
	Car(std::tuple<int, int, double> tuple, int dist);
};

Car::Car() : Transport()
{
	price = 100;
	speed = 60;
	volume = 50;
}

Car::Car(std::tuple<int, int, double> tuple, int dist)
{
	this->carPrice = std::get<0>(tuple);
	this->carSpeed = std::get<1>(tuple);
	this->carVolume = std::get<2>(tuple);
	this->distance = dist;
}

Car::Car(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist)
{
}

class Plane : public Transport
{
public:
	Plane();
	Plane(std::tuple<int, int, double> tuple, int dist);
};

Plane::Plane() : Transport()
{
	price = 500;
	speed = 300;
	volume = 100;
}

Plane::Plane(std::tuple<int, int, double> tuple, int dist)
{
	this->planePrice = std::get<0>(tuple);
	this->planeSpeed = std::get<1>(tuple);
	this->planeVolume = std::get<2>(tuple);
	this->distance = dist;
}

Plane::Plane(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist)
{
}

class Track
{
	double cost;
	double time;
	int volume;
public:
	Track();
	Track(Car, int);
	Track(Car, Car, Train, int);
	Track(Car, Car, Plane, int);
	Track(Car, Car, Car, Train, Plane, int);
	Track(Car, Car, Car, Car, Train, Train, Plane, int);
	double getCost();
	~Track();
};

class Order
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;
public:
	Order();
	Order(Type, std::string, std::string, int);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};

Track::Track()
{
	this->cost = 0;
	this->time = 0;
	this->volume = 0;
}

Track::~Track()
{

}

Track::Track(Car car1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance());
	time = car1.sumTime(car1.getDistance());
}

Track::Track(Car car1, Car car2, Train train1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance());
	cost += train1.sumCost(volume, train1.getDistance());
	time += train1.sumTime(train1.getDistance());
}

Track::Track(Car car1, Car car2, Plane plane1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance());
	cost += plane1.sumCost(volume, plane1.getDistance());
	time += plane1.sumTime(plane1.getDistance());
}

Track::Track(Car car1, Car car2, Car car3, Train train1, Plane plane1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance()) + car3.sumCost(volume, car3.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance()) + car3.sumTime(car3.getDistance());
	cost += train1.sumCost(volume, train1.getDistance());
	time += train1.sumTime(train1.getDistance());
	cost += plane1.sumCost(volume, plane1.getDistance());
	time += plane1.sumTime(plane1.getDistance());
}

Track::Track(Car car1, Car car2, Car car3, Car car4, Train train1, Train train2, Plane plane1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance()) + car3.sumCost(volume, car3.getDistance()) + car4.sumCost(volume, car4.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance()) + car3.sumTime(car3.getDistance()) + car4.sumTime(car4.getDistance());
	cost += train1.sumCost(volume, train1.getDistance()) + train2.sumCost(volume, train2.getDistance());
	time += train1.sumTime(train1.getDistance()) + train2.sumTime(train2.getDistance());
	cost += plane1.sumCost(volume, plane1.getDistance());
	time += plane1.sumTime(plane1.getDistance());
}

double Track::getCost()
{
	return this->cost;
}

Order::Order()
{
	this->cost = 0;
	this->volume = 0;
	this->startPoint = "";
	this->finishPoint = "";
	this->track = Track();
	this->type = Type::Economy;
}

Order::Order(Type deliv, std::string startP, std::string finishP, int vol)
{
	this->startPoint = startP;
	this->finishPoint = finishP;
	type = deliv;
	this->track = best(startP, finishP, deliv, vol);
	this->cost = track.getCost();
	this->volume = vol;
}

Order::~Order()
{

}

Track Order::best(std::string startP, std::string finishP, Type deliv, int volume) {
	int start = decr(startP);
	int finish = decr(finishP);
	int** mat = matrixUpd(deliv);
	int* path = optim(mat, start, finish);
	int count = 0;

	// Count non-negative elements in path array
	for (int i = 0; i < SIZE && path[i] != -1; ++i, ++count);

	switch (count) {
	case 1: {
		Car car1 = createCar(path[0]);
		return Track(car1, volume);
	}
	case 3: {
		Car car1 = createCar(path[0]);
		Car car2 = createCar(path[2]);
		Transport* transport = createTransport(path[1]);
		return Track(car1, car2, *transport, volume);
	}
	case 5: {
		Car car1 = createCar(path[0]);
		Car car2 = createCar(path[2]);
		Car car3 = createCar(path[4]);
		Transport* transport1 = createTransport(path[1]);
		Transport* transport2 = createTransport(path[3]);
		return Track(car1, car2, car3, *transport1, *transport2, volume);
	}
	case 7: {
		Car car1 = createCar(path[0]);
		Car car2 = createCar(path[2]);
		Car car3 = createCar(path[4]);
		Car car4 = createCar(path[6]);
		Train train1 = createTrain(path[1]);
		Train train2 = createTrain(path[5]);
		Plane plane1 = createPlane(path[3]);
		return Track(car1, car2, car3, car4, train1, train2, plane1, volume);
	}
	}
}

Car Order::createCar(int index) {
	for (auto it = table.begin(); it != table.end(); ++it) {
		if ((*it).first.find(points[index])) {
			return Car(tableCost[(*it).second * 3 + 2], matrixDist[index][index + 1]);
		}
	}
	return Car(); // Return default Car if not found
}

Train Order::createTrain(int index) {
	for (auto it = table.begin(); it != table.end(); ++it) {
		if ((*it).first.find(points[index]) && points[index].find("TS")) {
			return Train(tableCost[(*it).second * 3 + 1], matrixDist[index][index + 1]);
		}
	}
	return Train(); // Return default Train if not found
}

Plane Order::createPlane(int index) {
	for (auto it = table.begin(); it != table.end(); ++it) {
		if ((*it).first.find(points[index]) && points[index].find("AP")) {
			return Plane(tableCost[(*it).second * 3], matrixDist[index][index + 1]);
		}
	}
	return Plane(); // Return default Plane if not found
}

Transport* Order::createTransport(int index) {
	if (points[index].find("TS")) {
		return new Train(createTrain(index));
	}
	else if (points[index].find("AP")) {
		return new Plane(createPlane(index));
	}
	else {
		return nullptr; // Handle error case
	}
}


int** Order::matrixUpd(Type type)
{
	int** matrix = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		matrix[i] = new int[SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = matrixDist[i][j];
		}
	}
	switch (type)
	{
	case Economy:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("TS"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
	case Standart:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("AP"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
	case Turbo:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = 99999;
		}
	}
	return matrix;
}

int* Order::optim(int** arr, int beginPoint, int endPoint)
{
	int* d = new int[SIZE];
	int* v = new int[SIZE];
	int minindex, min;
	int begin_index = beginPoint;

	std::fill(d, d + SIZE, 99999);
	std::fill(v, v + SIZE, 1);
	d[begin_index] = 0;

	do {
		minindex = 99999;
		min = 99999;
		for (int i = 0; i < SIZE; i++)
		{
			if (v[i] && d[i] < min)
			{
				min = d[i];
				minindex = i;
			}
		}

		if (minindex != 99999)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (arr[minindex][i] > 0)
				{
					int temp = min + arr[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 99999);

	int* ver = new int[SIZE];
	int end = endPoint;
	ver[0] = end;
	int k = 1;
	int weight = d[end];

	while (end != begin_index)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[end][i] != 0 && weight - arr[end][i] == d[i])
			{
				weight = weight - arr[end][i];
				end = i;
				ver[k++] = i + 1;
			}
		}
	}
	std::reverse(ver, ver + k);
	delete[] d, v;
	return ver;
}


int Order::decr(std::string str)
{
	for (auto it = towns.begin(); it != towns.end(); it++)
	{
		if (str._Equal((*it).first))
			return (*it).second;
	}
	return -1;
}