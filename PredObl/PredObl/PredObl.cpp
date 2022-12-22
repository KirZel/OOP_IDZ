#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


class Processor {
    std::string proccessorSocket;
    int Hz;
    int W;
    public:   int Calc(int a, int b) {
        a = a + b;
        std::cout << a;
        return a;
    }
};

struct RAM {
    friend bool operator==(RAM r1, RAM r2);
    int MemoryAmount;
    int HGz;
};

class Graphic_Card {
    int AllMemory = 2048;
    int usedMemory = 512;
};



class MotherBoard {
    std::array <RAM*, 4> ram={nullptr};
public: std::ptrdiff_t getRamCount{
    std::count_if(ram.begin(),ram.end(),[](RAM* elem) {return elem != nullptr;})
};

public: void InsertRam(RAM g) {
    for (int i = 0; i < 4; i++) {
        if (ram[i] == nullptr) { ram[i] = &g; break; }
    }
}

public: RAM& GetRam(int n) {
        return *(ram[n]);
}

public: void RemoveRam(RAM g) {
    for (int i = 0; i <= 4; i++) {
        if (ram[i] == &g) { ram[i] = nullptr; }
    }
}


    std::string proccessorSlotSocket = "v1151";
    bool haveProcessor = true;
    bool haveGraphicCard = true;
    int RAMSlotsBusy = 2;
};

struct EventArg
{
    int x;
    int y;
    int key;
};

class Device {
public:
    virtual void Input(EventArg) = 0;
};

class Mouse : public Device {
    virtual void Input(EventArg e) {
        std::cout << "Mouse loc " << e.x << " " << e.y;
    }
};

class KeyBoard : public Device {
    virtual void Input(EventArg  e) {
        std::cout << "Key " << e.key;
    }
};


class PC :public MotherBoard, public Processor, public Graphic_Card, public RAM {
    std::vector<Device*> Devices;
public: std::vector<Device*> GetDivice()
{
    return Devices;
}
      void AddDevice(Device* d) {
          Devices.push_back(d);
     }
};


bool operator==(RAM r1, RAM r2) {
    return (r1.MemoryAmount == r2.MemoryAmount && r1.HGz == r2.HGz);
}

int main()
{
    Processor P;
    MotherBoard M;
    Graphic_Card G;
    RAM R{1024,3200};
    RAM T{1024,3200};
    PC PC;

    M.InsertRam(T);


    if (R == T) std::cout << "T"; else std::cout << "F";



    PC.AddDevice(new Mouse);
    PC.AddDevice(new KeyBoard);

    EventArg e{ 11, 12, 44 };

    for (auto& device : PC.GetDivice())
    {
        device->Input(e);
        std::cout << "\n";
    }
    return 0;
}

