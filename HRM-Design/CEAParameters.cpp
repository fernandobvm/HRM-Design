class CEAParameters {
protected:
    string fuel;
    string oxidizer;
    float thrust;
    float chamber_pressure;
    float of;
    float c_star;
    float cf;
    float area_ratio;
    float Isp;

public:
    CEAParameters(string _fuel, string _oxidizer, float _thrust, float _chamber_pressure, float _of, float _c_star, float _cf, float _area_ratio, float _Isp);
    ~CEAParameters();

    void readValues();
};

CEAParameters::CEAParameters(string _fuel, string _oxidizer, float _thrust, float _chamber_pressure, float _of, float _c_star, float _cf, float _area_ratio, float _Isp) {
    fuel = _fuel;
    oxidizer = _oxidizer;
    thrust = _thrust;
    chamber_pressure = _chamber_pressure;
    of = _of;
    c_star = _c_star;
    cf = _cf;
    area_ratio = _area_ratio;
    Isp = _Isp;
}

CEAParameters::~CEAParameters() {
    cout << "Classe Destruída\n";
}

void CEAParameters::readValues() {
    string fuel;
    string oxidizer;
    float thrust;
    float chamber_pressure;
    float of;
    float c_star;
    float cf;
    float area_ratio;
    float Isp;

    cout << "Insira o combustível:\n";
    cin >> fuel;
    cout << "Insira o oxidante:\n";
    cin >> oxidizer;
    cout << "Insira o empuxo:\n";
    cin >> thrust;
    cout << "Insira a pressão na câmara:\n";
    cin >> chamber_pressure;
    cout << "Insira a razão of:\n";
    cin >> of;
    cout << "Insira o c star:\n";
    cin >> c_star;
    cout << "Insira o cf:\n";
    cin >> cf;
    cout << "Insira a razão de expansão:\n";
    cin >> area_ratio;
    cout << "Insira o Isp:\n";
    cin >> Isp;

}