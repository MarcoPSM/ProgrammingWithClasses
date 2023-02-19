/*
 * No fim de fazer a estrutura de pastas e criar os CMakes
 * ir a File->Reload CMake Project
 * e depois Build->Build Project
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Point.h"
#include "Triangle.h"

using namespace mar;

void TestPoint();
void TestWriteRead();
void TestTriangle();
void TestStringOperations();

int main() {
    std::cout << "Programação com classes" << std::endl;
    //TestPoint();
    //TestWriteRead();
    //TestTriangle();
    //TestStringOperations();

    return 0;
}

void TestStringOperations() {
    std::string s1;
    std::string s2;
    std::cout << "uma palavra: ";
    std::cin >> s1;
    for (int i = 0; i < static_cast<int>(s1.size()); i++) {
        std::cout << " " << s1[i];
    }
    std::cout << std::endl;
    s2 = "<" + s1 + ">";
    std::cout<<s2<<std::endl;


    std::cout << "Duas palavras: ";
    std::cin >> s1 >> s2;
    std::cout << "<" << s1 << "> <" << s2 << ">" << std::endl;
    if (s1==s2) {
        std::cout << "iguais";
    } else {
        std::cout << "diferentes";
    }
    std::cout << std::endl;

    std::string name;
    std::cout << "Nome do ficheiro com os pontos: ";
    std::cin >> name; // /home/marco/Desktop/teste_in.txt
    std::ifstream input(name.c_str());
    if (!input) {
        std::cout << "Ficheiro nao existe" << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }
}

void TestTriangle() {
    Point p0, p1, p2;
    std::cout << "Teste das ops do triangulo" << std::endl;
    std::cout << "Tres pontos: ";
    p0.Read();
    p1.Read();
    p2.Read();
    Triangle t(p0,p1,p2);
    std::cout << std::fixed << std::setprecision(2);
    bool done = false;
    do {
        t.WriteLine(std::cout);
        std::cout << t.Area()<<std::endl;
        std::cout << t.Perimeter()<<std::endl;
        std::cout << "e_scalar, t_ransladar, r_odar, s_air: ";
        std::string reply;
        std::cin >> reply;
        switch(reply[0]) {
            case 'e':
                t.Scale(2,2);
                break;
            case't':
                t.Translate(1,1);
                break;
            case 'r':
                t.Rotate(3.1416/2);
                break;
            case 's':
                done = true;
                break;
        }
    } while (!done);
    std::cout << "Fim!"<<std::endl;
}

void TestWriteRead() {
    Point p;
    // escrever para um ficheiro
    std::ofstream output("/home/marco/Desktop/teste_out.txt");
    p.WriteLine(output);
    // ler do ficheiro
    std::ifstream input("/home/marco/Desktop/teste_in.txt");
    p.Read(input);
    std::cout << "Ponto do ficheiro: ";
    p.WriteLine();
}

void TestPoint() {
    Point p, q;
    double d;
    int n;

    p.WriteLine();
    p.Translate(2.0, 3.5);

    d = p.DistanceTo(q);
    std::cout << d;
    std::cout << "Teste: Numero de vertices:";
    std::cin >> n;
    std::cout << "Coordenadas iniciais: ";
    p.Read();

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; ++i) {
        p.WriteLine();
        p.Rotate(2*3.1415926535 / n);
    }
}

