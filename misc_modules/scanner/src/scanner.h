#ifndef SCANNERMODULE_H
#define SCANNERMODULE_H

#include <imgui.h>
#include <module.h>
#include <gui/gui.h>
#include <gui/style.h>
#include <signal_path/signal_path.h>

class ScannerModule : public ModuleManager::Instance {
public:
    ScannerModule(std::string name);
    ~ScannerModule();
    void postInit();
    void enable();
    void disable();
    bool isEnabled();
    void HPStart();
    void HPStop();

private:
    void start();
    void stop();
    static void menuHandler(void* ctx);
    void worker();
    bool findSignal(bool scanDir, double& bottomLimit, double& topLimit, double wfStart, double wfEnd, double wfWidth, double vfoWidth, float* data, int dataWidth);
    float getMaxLevel(float* data, double freq, double width, int dataWidth, double wfStart, double wfWidth);

    std::string name;
    bool enabled = true;
    
    bool running = false;
    //std::string selectedVFO = "Radio";
    double startFreq = 88000000.0;
    double stopFreq = 108000000.0;
    double interval = 100000.0;
    double current = 88000000.0;
    double passbandRatio = 10.0;
    int tuningTime = 250;
    int lingerTime = 1000.0;
    float level = -50.0;
    bool receiving = true;
    bool tuning = false;
    bool scanUp = true;
    bool reverseLock = false;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastSignalTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTuneTime;
    std::thread workerThread;
    std::mutex scanMtx;

public:
    static ScannerModule* globalScanner; // Declaration of static member variable
};

#endif // SCANNERMODULE_H
