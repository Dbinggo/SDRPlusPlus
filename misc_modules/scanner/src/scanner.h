#ifndef HPSCANNER  
#define HPSCANNER  
  
#include <string>  
#include <module.h> // 确保这个头文件包含了ModuleManager::Instance的定义  

class ScannerModule : public ModuleManager::Instance {  
public:  
    ScannerModule(std::string name);  
   
    static ScannerModule* globalScanner; 

    void HPStop();
    void HPStart();

private:
    void stop();
    void Pstart();
  
   
};  

  
#endif // SCANNERMODULE_H
