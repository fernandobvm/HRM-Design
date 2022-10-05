// HRM-Design.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

using namespace std;

class Propellant {
protected:
    string fuel;
    float fuel_density;
    string oxidizer;
    float oxidizer_density;
    float a;
    float n;
    float A;
    float B;
    float C;
public:
    Propellant();
    ~Propellant();

    void setPropellant(string _fuel, float _fuel_density, string _oxidizer, float _oxidizer_density, float _a, float _n, float _A, float _B, float _C);
    void readPropellant();

    float calculatePressure(float _temperature);

};

Propellant::Propellant() {}

Propellant::~Propellant() {}

void Propellant::setPropellant(string _fuel, float _fuel_density, string _oxidizer, float _oxidizer_density, float _a, float _n, float _A, float _B, float _C) {
    fuel = _fuel;
    fuel_density = _fuel_density;
    oxidizer = _oxidizer;
    oxidizer_density = _oxidizer_density;
    a = _a;
    n = _n;
    A = _A;
    B = _B;
    C = _C;
}

void Propellant::readPropellant() {
    string fuel;
    float fuel_density;
    string oxidizer;
    float oxidizer_density;
    float a;
    float n;

    cout << "Insira o combustivel:\n";
    cin >> fuel;
    cout << "Insira a densidade do combustivel:\n";
    cin >> fuel_density;
    cout << "Insira o oxidante:\n";
    cin >> oxidizer;
    cout << "Insira a densidade do oxidante:\n";
    cin >> oxidizer_density;
    cout << "Insira o coeficiente a:\n";
    cin >> a;
    cout << "Insira o coeficiente n:\n";
    cin >> n;
    cout << "Insira os coeficientes do diagrama P-T:\n";
    cin >> A;
    cin >> B;
    cin >> C;

    Propellant::setPropellant(fuel, fuel_density, oxidizer, oxidizer_density, a, n, A, B, C);
}

float Propellant::calculatePressure(float _temperature) {
    return C * _temperature * _temperature + B * _temperature + A;
}

class Ambient {
protected:
    float ambient_temperature;

public:
    Ambient();
    ~Ambient();

    void setAmbient(float _ambient_temperature);
};

Ambient::Ambient() {}
Ambient::~Ambient() {}

void Ambient::setAmbient(float _ambient_temperature) {
    ambient_temperature = _ambient_temperature;
}


class Motor {
protected:
    float thrust;
    float chamber_pressure;
    float of;
    float cf;
    float c_star;
    float area_ratio;
    float Isp;
    float burning_time;
    float n_port;
    float initial_port_diameter;
    Ambient ambient;
    Propellant propellant;

public:
    Motor();
    ~Motor();

    void setParameters(float _thrust, float _chamber_pressure, float _of, float _cf, float _c_star, float _area_ratio, float _Isp, float _burning_time, float _n_port, float _initial_port_diameter, Ambient _ambient, Propellant _propellant);
};

Motor::Motor() {}
Motor::~Motor() {}

void Motor::setParameters(float _thrust, float _chamber_pressure, float _of, float _cf, float _c_star, float _area_ratio, float _Isp, float _burning_time, float _n_port, float _initial_port_diameter, Ambient _ambient, Propellant _propellant) {
    thrust = _thrust;
    chamber_pressure = _chamber_pressure;
    of = _of;
    cf = _cf;
    c_star = _c_star;
    area_ratio = _area_ratio;
    Isp = _Isp;
    burning_time = _burning_time;
    n_port = _n_port;
    initial_port_diameter = _initial_port_diameter;
    ambient = _ambient;
    propellant = _propellant;
}


int main()
{
    cout << "Hello World!\n";
    
    
}
