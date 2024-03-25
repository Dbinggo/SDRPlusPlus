#ifndef HPSCANNER  
#define HPSCANNER  
  
#include <imgui.h>
#include <module.h>
#include <gui/gui.h>
#include <gui/style.h>
#include <signal_path/signal_path.h> 

class ScannerModule : public ModuleManager::Instance {  
    
    public:  
        static ScannerModule* globalScanner; 
        ScannerModule(std::string name);  
        ~ScannerModule();
        void postInit();
        void enable();
        void disable();
        bool isEnabled();
        void HPStop();
        void HPStart();

    private:
        void stop();
        void start();
        void menuHandler(void* ctx)
};  

  
#endif // SCANNERMODULE_H
