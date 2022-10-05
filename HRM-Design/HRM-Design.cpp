// HRM-Design.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cmath>

#define PI 3.141592653589793

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

    double getFuelDensity();
    double getOxidizerDensity();

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

double Propellant::getFuelDensity() {
    return fuel_density;
}

double Propellant::getOxidizerDensity(){
    return oxidizer_density;
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
    double orifice_diameter;
    double injection_area;
    double orifice_number;
public:

    Injector();
    ~Injector();

    void setInjector(string _type, double _discharge_coefficient, double _orifice_diameter);
    void calculateInjector( double _dot_m_oxidizer, double _delta_pressure, double _oxidizer_density);
};

Injector::Injector() {}
Injector::~Injector() {}

void Injector::setInjector(string _type, double _discharge_coefficient, double _orifice_diameter) {
    type = _type;
    discharge_coefficient = -discharge_coefficient;
    orifice_diameter = _orifice_diameter;
}

void Injector::calculateInjector(double _dot_m_oxidizer, double _delta_pressure, double _oxidizer_density ){
    injection_area = _dot_m_oxidizer / (discharge_coefficient * sqrt(2 * _oxidizer_density * _delta_pressure));
    orifice_number = 4 * injection_area / (PI * pow(orifice_diameter, 2));

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

    double throat_area;
    double throat_diameter;
    double exit_area;

    //Total values
    double dot_m_propellant;
    double dot_m_fuel;
    double dot_m_oxidizer;

    double oxidizer_mass;
    double fuel_mass;
    double propellant_mass;

    void calculateParameters();

public:
    Motor();
    ~Motor();

    void setParameters(double _thrust, double _chamber_pressure, double _of, double _cf, double _c_star, double _ef_c_star, double _area_ratio, double _Isp, double _burning_time, double _n_port, double _initial_port_diameter, Ambient _ambient, Propellant _propellant, Injector _injector);
    double getThroatArea();
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

    Motor::calculateParameters();
}

void Motor::calculateParameters(){
    throat_area = thrust / (chamber_pressure * cf);
    throat_diameter = sqrt  (4 * throat_area / PI);
    exit_area = area_ratio * throat_area;

    dot_m_propellant = chamber_pressure * throat_area / cf;
    dot_m_fuel = dot_m_propellant / (of + 1);
    dot_m_oxidizer = dot_m_propellant - dot_m_fuel;

    oxidizer_mass = dot_m_oxidizer * burning_time;
    fuel_mass = dot_m_fuel * burning_time;
    propellant_mass = oxidizer_mass + fuel_mass;

    injector.calculateInjector(dot_m_oxidizer, tank_pressure - chamber_pressure, propellant.getOxidizerDensity());

    //TODO: Calculate tank dimensions
}

double Motor::getThroatArea() {
    return throat_area;
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
    injetor.setInjector("Default", 0.4, 2.6 / 1000);
    propelente.setPropellant("Paraffin", 920.0, "N2O", 720.0, 0.467, 0.543, 3039240, 79752.817, 773.269);
    motor.setParameters(1500, 3000000, 5, 1.49, 1578.84102, 0.8, 5.0, 235.17805, 5.0, 1, 0.03, ambiente, propelente, injetor);
    simulacao.setSimulation(0.01, motor);

    cout << "Throat Area (m2): " << motor.getThroatArea();
}
