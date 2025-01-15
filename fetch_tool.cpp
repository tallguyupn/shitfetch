#include <iostream>
#include <string>
#include <fstream>

//function that checks the cpu info
std::string cpu (const std::string& cpu);

//function to get the core amount
int cores_amount (const int& core_amount1); 

int main (){
    std::string os;
    std::string ram;
    std::string gpu;


    std::string cpu_info = cpu(cpu_info);
    int core_amount1 = cores_amount(core_amount1);

    std::cout << "cpu " << cpu_info << "\n";
    std::cout << "cores: " << core_amount1 << std::endl;

}

std::string cpu (const std::string& cpu){
    std::ifstream infile("/proc/cpuinfo"); ///open the file that has the cpu info

    if (!infile) {
        throw std::runtime_error("Cpu info not accesed"); //if you cant open the file, quit
    }

    std::string line;
    std::string start_text="model name";


    while (std::getline(infile, line)) {
        if (line.rfind(start_text,0 ) == 0) {
            return line;
        }
    }


    throw std::runtime_error("Cpu info file '/proc/cpuinfo' is not written as should");


}

int cores_amount (const int& core_amount1){   
    std::ifstream infile("/proc/cpuinfo"); ///open the file that has the cpu info
        if (!infile) {
          throw std::runtime_error("Cpu info not accesed"); //if you cant open the file, quit
        }
        int amount=0;
        std::string line;
        std::string cores="processor";

        while (std::getline(infile, line)){
            if (line.rfind(cores, 0) == 0) {
                amount++;
            }
        }
        return amount;

   
}    