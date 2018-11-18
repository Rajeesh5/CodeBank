#include<iostream>
#include<list>
#include<thread>
#include<algorithm>

using namespace std;

//Structure Contains Weather Info.
struct WeatherRawInfo {
	float temperature;
	float humidity;
	float pressure;
};

class Sensor {
public:
	virtual float fatchData() = 0;
	//virtual ~Sensor() = 0;
};

class TempartureSensor :public Sensor {
public:
	const float MaxTempReading = 100.0; // in Centigrate.
	float fatchData() {
		float factor = static_cast<float>(rand())/static_cast<float>(RAND_MAX);
		return (static_cast<float>(MaxTempReading) *factor);
	}
	~TempartureSensor() {
		//delete this;
	}
};

class PressureSensor : public Sensor {
public:
	const float MaxPressureReading = 56.0; // in PSI.
	float fatchData() {
		float factor = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		return ((MaxPressureReading) *factor);
	}
	~PressureSensor() {
		//delete this;
	}
};

class HumiditySensor :public Sensor {
public:
	const float MaxHumidityReading = 100.0; // in %
	float fatchData() {
		float factor = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		return ((MaxHumidityReading) *factor);
	}
	~HumiditySensor() {
		//delete this;
	}
};


//Virtrual Base Observer Class
class Observer {
public:
	virtual void update(list<WeatherRawInfo>&) = 0;
};

//Virtual Base Subject Class
class Subject{
public:
	virtual void registerObserver(Observer* s)=0;
	virtual void removeObserver(Observer* s) = 0;
	virtual void notifyObserver() = 0;
};

//Concreat Subject Class,thread Based live station.
class WeatherStation : public Subject {

	list<WeatherRawInfo> weatherRawInfoList;
	const int MaxReading = 10;
	list<Observer*> observerList;
	std::thread *workerThread;
	bool isReady;
	Sensor *sensor;

public:
	WeatherStation():isReady(true){	
	}
	
	~WeatherStation() {

		isReady = false;
		if (workerThread->joinable())
			workerThread->join();

		delete workerThread;
		delete sensor;
	}

	void registerObserver(Observer *o) {
		observerList.push_back(o);
	}
	
	void removeObserver(Observer *o) {
		observerList.remove(o);
	}
	
	void notifyObserver() {
	
		
			list<Observer*>::iterator iter = observerList.begin();
			for (; iter != observerList.end(); iter++)
				(*iter)->update(weatherRawInfoList);
		

		//std::for_each(observerList.begin(), observerList.end(), update(temperature, humidity, pressure));
		
	}
	
	void measurementsChanged() {
		notifyObserver();
	}

	void setMeasurement() {
		while (isReady)
		{
			WeatherRawInfo tmp;
			TempartureSensor ts;
			HumiditySensor hs;
			PressureSensor ps;

			std::this_thread::sleep_for(std::chrono::seconds(1));

			sensor = &ts;
			tmp.temperature = sensor->fatchData();

			sensor = &hs;
			tmp.humidity = sensor->fatchData();

			sensor = &ps;
			tmp.pressure = sensor->fatchData();

			int size = weatherRawInfoList.size();

			if (size <= MaxReading) {
				weatherRawInfoList.push_back(tmp);
			}
			else {
				weatherRawInfoList.pop_front();
				weatherRawInfoList.push_back(tmp);
			}


			measurementsChanged();
		}
	}

	//starts the Thread based method setMeasurement which sets measurement & notify the observer.
	void startSenseing() {
		workerThread = new thread(&WeatherStation::setMeasurement, this);
	}

};

//Widget Base class,not much importent.
class Widget : public Observer{
public:
	virtual void display(WeatherRawInfo&) = 0;
};

//Concreat Observer Class
class CurrentWeatherWidget :public Widget
{
public:

	void update(list<WeatherRawInfo> &wInfo) {
		WeatherRawInfo currentReadVlu =  wInfo.back();
		display(currentReadVlu);
	}

	void display(WeatherRawInfo &t) {
		cout << "Current Temprature::" << t.temperature << " Humidity::" << t.humidity << " Pressure::" << t.pressure << endl;
	}
};

//Concreat Observer Class
class StaticWeatherWidget :public Widget
{



}; 


void main() {

	//Subject creation.
	WeatherStation *wd = new WeatherStation();
	wd->startSenseing();		//Now workstation is live, its start senseing all the parameter.

	//Observer creation.
	CurrentWeatherWidget *cwd = new CurrentWeatherWidget();

	//Register the Observer
	wd->registerObserver(cwd);

	getchar();
}





