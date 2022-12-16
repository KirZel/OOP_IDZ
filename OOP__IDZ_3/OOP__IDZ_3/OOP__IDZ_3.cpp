#include <iostream>
#include <fstream>
#include <string>


struct scan_info
{
    std::string model; // наименование модели
    int price; // цена
    double x_s1ze; // горизонтальный размер области сканирования
    double y_s1ze; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
    int grey; // число градаций серого
};


void Write(int num) {
    scan_info* Mas = new scan_info[num];
    for (int i = 0; i < num; i++) {

        std::cout << "Model ";
        std::cin >> Mas[i].model;

        while (true) {
            std::cout << "Price ";
            std::cin >> Mas[i].price;
            if ((std::cin.fail()) || (Mas[i].price <= 0))
            {std::cin.clear(); std::cout << "Input Error. Try again" << std::endl; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}else { break; }}

        while (true) {
            std::cout << "Size x ";
            std::cin >> Mas[i].x_s1ze;
            if ((std::cin.fail()) || (Mas[i].x_s1ze <= 0))
            {std::cin.clear(); std::cout << "Input Error. Try again" << std::endl; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}else { break; }}

        while (true) {
            std::cout << "Size y ";
            std::cin >> Mas[i].y_s1ze;
            if ((std::cin.fail()) || (Mas[i].y_s1ze <= 0))
            {std::cin.clear(); std::cout << "Input Error. Try again" << std::endl; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}else { break; }}

        while (true) {
            std::cout << "Optic ";
            std::cin >> Mas[i].optr;
            if ((std::cin.fail()) || (Mas[i].optr <= 0))
            {std::cin.clear(); std::cout << "Input Error. Try again" << std::endl; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}else { break; }}

        while (true) {
            std::cout << "Grey ";
            std::cin >> Mas[i].grey;
            if ((std::cin.fail()) || (Mas[i].grey <= 0))
            {std::cin.clear(); std::cout << "Input Error. Try again" << std::endl; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}else { break; }}

    }

    std::fstream f1;
    f1.open("f.bin", std::ios::out | std::ios::binary);
    f1.write((char*)&num, sizeof(num));
    for (int i = 0; i < num; i++) {
        f1.write(Mas[i].model.data(), Mas[i].model.size() * sizeof(char));
        f1.write((char*)&"\0", sizeof(char));
        f1.write((char*)&Mas[i].price, sizeof(Mas[i].price));
        f1.write((char*)&Mas[i].x_s1ze, sizeof(Mas[i].x_s1ze));
        f1.write((char*)&Mas[i].y_s1ze, sizeof(Mas[i].y_s1ze));
        f1.write((char*)&Mas[i].optr, sizeof(Mas[i].optr));
        f1.write((char*)&Mas[i].grey, sizeof(Mas[i].grey));
        f1.write((char*)&"\0", sizeof(char));
    }
    f1.close();
    delete[] Mas;
}


int Read(scan_info* sp, int n)
{   
    int a;
    std::fstream f1;
    f1.open("f.bin", std::ios::in | std::ios::binary);
    if (!f1.is_open()) { std::cout << "File Error" << '\n'; return -1; }
    f1.read((char*)&a, sizeof(int));
    if (n > a) { std::cout << "Nember of infos Error" << '\n'; return -1; }
    for (int i = 1; i <= n; i++) {
        std::string mod;
        char s;
        f1.read((char*)&s, sizeof(char));
        while (s != '\0') {
            mod = mod + s;
            f1.read((char*)&s, sizeof(char));
             }
        sp->model = mod;
        f1.read((char*)&sp->price, sizeof(int));
        f1.read((char*)&sp->x_s1ze, sizeof(double));
        f1.read((char*)&sp->y_s1ze, sizeof(double));
        f1.read((char*)&sp->optr, sizeof(int));
        f1.read((char*)&sp->grey, sizeof(int));
        f1.read((char*)&s, sizeof(char));
    }
    f1.close();
    return 0;
}

int main() {
    std::cout << "Col-vo zapisei";
    int b;
    std::cin >> b;
    std::cout << "Nomer zapisi vivoda";
    int g;
    std::cin >> g;
   scan_info* output = new scan_info;
    Write(b);
    if (Read(output, g) == 0)  std::cout << "Read is succesd";  else std::cout << "Error of file reading"; std::cout << '\n';
    std::cout << "Model:" << output->model << '\n';
    std::cout << "Price:" << output->price << '\n';
    std::cout << "Size x:" << output->x_s1ze << '\n';
    std::cout << "Size y:" << output->y_s1ze << '\n';
    std::cout << "Optic:" << output->optr << '\n';
    std::cout << "Grey:" << output->grey << '\n';
    delete output;
}
