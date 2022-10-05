// HRM-Design.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

using namespace std;

class Propellant {
protected:
    string fuel;
    double fuel_density;
    string oxidizer;
    double oxidizer_density;
    double a;
    double n;
    double A;
    double B;
    double C;
public:
    Propellant();
    ~Propellant();

    void setPropellant(string _fuel, double _fuel_density, string _oxidizer, double _oxidizer_density, double _a, double _n, double _A, double _B, double _C);
    void readPropellant();

    double calculatePressure(double _temperature);

};

Propellant::Propellant() {}

Propellant::~Propellant() {}

void Propellant::setPropellant(string _fuel, double _fuel_density, string _oxidizer, double _oxidizer_density, double _a, double _n, double _A, double _B, double _C) {
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
    double fuel_density;
    string oxidizer;
    double oxidizer_density;
    double a;
    double n;

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

double Propellant::calculatePressure(double _temperature) {
    return C * _temperature * _temperature + B * _temperature + A;
}

class Ambient {
protected:
    double ambient_temperature;

public:
    Ambient();
    ~Ambient();

    void setTemperature(double _ambient_temperature);
    double getTemperature();
};

Ambient::Ambient() {}
Ambient::~Ambient() {}

void Ambient::setTemperature(double _ambient_temperature) {
    ambient_temperature = _ambient_temperature;
}

double Ambient::getTemperature() {
    return ambient_temperature;
}

class Injector {
protected:
    string type;
    double discharge_coefficient;
public:

    Injector();
    ~Injector();

    void setInjector(string _type, double _discharge_coefficient);
};

Injector::Injector() {}
Injector::~Injector() {}

void Injector::setInjector(string _type, double _discharge_coefficient) {
    type = _type;
    discharge_coefficient = -discharge_coefficient;
}

class Motor {
protected:
    double thrust;
    double chamber_pressure;
    double of;
    double cf;
    double c_star;
    double ef_c_star;
    double exp_c_star;
    double area_ratio;
    double Isp;
    double burning_time;
    double n_port;
    double initial_port_diameter;
    double tank_pressure;
    Ambient ambient;
    Propellant propellant;
    Injector injector;

public:
    Motor();
    ~Motor();

    void setParameters(double _thrust, double _chamber_pressure, double _of, double _cf, double _c_star, double _ef_c_star, double _area_ratio, double _Isp, double _burning_time, double _n_port, double _initial_port_diameter, Ambient _ambient, Propellant _propellant, Injector _injector);
};

Motor::Motor() {}
Motor::~Motor() {}

void Motor::setParameters(double _thrust, double _chamber_pressure, double _of, double _cf, double _c_star, double _ef_c_star, double _area_ratio, double _Isp, double _burning_time, double _n_port, double _initial_port_diameter, Ambient _ambient, Propellant _propellant, Injector _injector) {
    thrust = _thrust;
    chamber_pressure = _chamber_pressure;
    of = _of;
    cf = _cf;
    c_star = _c_star;
    ef_c_star = _ef_c_star;
    exp_c_star = _c_star * _ef_c_star;
    area_ratio = _area_ratio;
    Isp = _Isp;
    burning_time = _burning_time;
    n_port = _n_port;
    initial_port_diameter = _initial_port_diameter;
    ambient = _ambient;
    propellant = _propellant;
    injector = _injector;
    tank_pressure = _propellant.calculatePressure(_ambient.getTemperature());
}


class Simulation {
protected:
    double timestep;
    Motor motor;
public:
    Simulation();
    ~Simulation();

    void setSimulation(double _timestep, Motor _motor);
};

Simulation::Simulation() {}
Simulation::~Simulation() {
    cout << "Classe Simulation destruida\n";
}

void Simulation::setSimulation(double _timestep, Motor _motor) {
    timestep = _timestep;
    motor = _motor;
}




int main()
{
    cout << "Hello World!\n";
    Ambient ambiente;
    Propellant propelente;
    Injector injetor;
    Motor motor;
    Simulation simulacao;
    
    ambiente.setTemperature(25.0);
    injetor.setInjector("Default", 0.4);
    propelente.setPropellant("Paraffin", 920.0, "N2O", 720.0, 0.467, 0.543, 3039240, 79752.817, 773.269);
    motor.setParameters(1500, 3000000, 5, 1.49, 1578.84102, 0.8, 5.0, 235.17805, 5.0, 1, 0.03, ambiente, propelente, injetor);
    simulacao.setSimulation(0.01, motor);
}
