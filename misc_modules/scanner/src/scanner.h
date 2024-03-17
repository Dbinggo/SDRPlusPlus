#ifndef HPSCANNER  
#define HPSCANNER  
  
#include <string>  
#include <module.h> // 确保这个头文件包含了ModuleManager::Instance的定义  

class ScannerModule : public ModuleManager::Instance {  
public:  

    static ScannerModule* globalScanner; 
    ScannerModule(std::string name);  
   
    

    void HPStop();
    void HPStart();

private:
    void stop();
    void start();
  
   
};  

  
#endif // SCANNERMODULE_H
