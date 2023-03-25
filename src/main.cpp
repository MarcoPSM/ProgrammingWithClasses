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
#include "Date.h"
#include "DateSpecial.h"
#include "Metrics.h"

using namespace mar;

void TestPoint();
void TestWriteRead();
void TestTriangle();
void TestStringOperations();
void TestDate();
void TestFriday13();
void TestBridges();
void TestDepartForVacations();
void TestMetrics();

int main() {
    std::cout << "Programação com classes" << std::endl;
    //TestPoint();
    //TestWriteRead();
    //TestTriangle();
    //TestStringOperations();
    //TestDate();
    //TestFriday13();
    //TestBridges();
    //TestDepartForVacations();
    TestMetrics();

    return 0;
}


void TestMetrics() {
    std::string fileName;
    std::cout << "Nome do ficheiro: ";
    std::getline(std::cin, fileName);
    std::cout << fileName << std::endl;
    std::ifstream input(fileName.c_str());
    if (!input) {
        std::cout << "Ficheiro inacessivel." << std::endl;
        return;
    }
    mar::Metrics m(input);
    std::cout << "Lines of Code = " << m.CountLinesOfCode() << std::endl;
    std::cout << "Lines with semicolons = " << m.CountLinesEndingWithSemicolon() << std::endl;

}

void TestDepartForVacations() {

    int n;
    std::cout << "Quantos dias de férias? ";
    std::cin >> n;
    int y;
    std::cout << "Em que ano? ";
    std::cin >> y;
    if (! mar::Date::Valid(y)) {
        return;
    }
    mar::DatePortuguese::SetFormat(mar::DatePortuguese::TEXT_WITH_WEEKDAY);
    mar::DateSpecial d = mar::DateSpecial::DepartForVacations(y, n);
    int x = d.DaysAway(n);
    std::cout << "Parta " << d << "." << std::endl
        << "Regresse "<< mar::DatePortuguese(d + x) << "." << std::endl
        << "Terá " << x << " dias de férias efectivos." << std::endl;
}

void TestBridges() {
    mar::DateSpecial d;d.Accept("Pontes a partir de que dia(ano mes dia)?", "Data inválida.");
    int n;
    std::cout << "Quantas pontes: ";
    std::cin >> n;
    mar::DatePortuguese::SetFormat(mar::DatePortuguese::TEXT_WITH_WEEKDAY);
    d.WriteBridges(std::cout, n);
}

void TestFriday13() {
    int count = 0;
    for(mar::DateSpecial d; count < 13; d++) {
        if (d.Friday13()) {
            count++;
            d.WriteLine();
        }
    }
}

void TestDate() {

    mar::Date birthdate;
    birthdate.Accept("Nasceste em que dia (ano mes dia)?", "Data invalida.");
    const mar::Date today;
    if (today < birthdate) {
        std::cout << "Afinal ainda nao nasceste." << std::endl;
    } else if (today == birthdate) {
        std::cout << "Nasceste hoje, parabens!." << std::endl;
    } else {
        mar::Date day(birthdate);
        int age = 0;
        do {
            day.Add(1000);
            age++;
        } while (day < today);
        int daysLeft = today.DaysTo(day);
        std::cout << "Fazes " << age * 1000 << " dias";
        if (daysLeft == 0) {
            std::cout << "HOJE!";
        } else {
            std::cout << " no dia " << day << ", ou seja,";
            if (daysLeft == 1) {
                std::cout << " AMANHA!";
            } else {
                std::cout << " daqui a " << daysLeft << " dias.";
            }
        }
        std::cout << std::endl;
    }
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

