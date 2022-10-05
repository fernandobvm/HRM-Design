// HRM-Design.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

using namespace std;

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
    CEAParameters();
    ~CEAParameters();

    void setParameters(string _fuel, string _oxidizer, float _thrust, float _chamber_pressure, float _of, float _c_star, float _cf, float _area_ratio, float _Isp);
    void readParameters();
    void printInfo();
};

CEAParameters::CEAParameters() {

}

CEAParameters::~CEAParameters() {
    cout << "Classe Destruida\n";
}

void CEAParameters::setParameters(string _fuel, string _oxidizer, float _thrust, float _chamber_pressure, float _of, float _c_star, float _cf, float _area_ratio, float _Isp) {
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

void CEAParameters::readParameters() {
    string fuel;
    string oxidizer;
    float thrust;
    float chamber_pressure;
    float of;
    float c_star;
    float cf;
    float area_ratio;
    float Isp;

    cout << "Insira o combustivel:\n";
    cin >> fuel;
    cout << "Insira o oxidante:\n";
    cin >> oxidizer;
    cout << "Insira o empuxo:\n";
    cin >> thrust;
    cout << "Insira a pressao na camara:\n";
    cin >> chamber_pressure;
    cout << "Insira a razao of:\n";
    cin >> of;
    cout << "Insira o c star:\n";
    cin >> c_star;
    cout << "Insira o cf:\n";
    cin >> cf;
    cout << "Insira a razao de expansao:\n";
    cin >> area_ratio;
    cout << "Insira o Isp:\n";
    cin >> Isp;

    CEAParameters::setParameters(fuel, oxidizer, thrust, chamber_pressure, of, c_star, cf, area_ratio, Isp);
}

void CEAParameters::printInfo(){
    cout << "NASA CEA Results\n";
    cout << "Fuel: " << fuel << endl;
    cout << "Oxidizer: " << oxidizer << endl;
    cout << "Thrust: " << thrust << endl;
    cout << "Chamber Pressure: " << chamber_pressure << endl;
    cout << "O/F: " << of << endl;
    cout << "c*: " << c_star << endl;
    cout << "CF: " << cf << endl;
    cout << "Ae/At: " << area_ratio << endl;
    cout << "Isp: " << Isp << endl;
}


int main()
{
    cout << "Hello World!\n";
    
    CEAParameters cea;
    //cea.readParameters();
    cea.setParameters("N2O", "Paraffin", 1500.0, 3000000, 5, 1578.841, 1.49, 5, 235.178);
    cea.printInfo();
    
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
