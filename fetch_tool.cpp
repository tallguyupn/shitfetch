/* to do list
1. make a gpu detector
2. make a linux logo
3. make a ram detector
*/




#include <iostream>
#include <string>
#include <fstream>

//function that checks the os version
std::string os_info(const std::string& os);

//function that checks the cpu info
std::string cpu (const std::string& cpu);

//function to get the core amount
int cores_amount (const int& core_amount1); 

int main (){

    
    std::string os = os_info(os);
    std::string cpu_info = cpu(cpu_info);
    int core_amount1 = cores_amount(core_amount1);

    std::cout << os << "\n";
    std::cout << "cpu " << cpu_info << "\n";
    std::cout << "cpu-threads: " << core_amount1 << std::endl;

}

std::string os_info(const std::string& os){
    std::ifstream infile("/etc/os-release");

    if (!infile) {
       throw std::runtime_error("Fatal: OS info could not be accessed\n"); 
    }

    std::string line;
    std::string start_text="PRETTY_NAME";

    while (std::getline(infile, line)) {
        if (line.rfind(start_text,0) == 0) {
            return line;
        }
    }

    throw std::runtime_error("Cpu info file '/proc/cpuinfo' is not written as should");
}

std::string cpu (const std::string& cpu){
    std::ifstream infile("/proc/cpuinfo"); ///open the file that has the cpu info

    if (!infile) {
        throw std::runtime_error("Cpu info not accesed\n"); //if you cant open the file, quit
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