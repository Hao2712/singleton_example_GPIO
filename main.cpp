#include <iostream>
#include <string>

class GPIO {
    private:
        static GPIO* instance;
        bool isInput;
        bool isOutput;
        GPIO() {
            isInput = false;
            isOutput = false;
        };
    
    public:
        static GPIO* getInstance() {
            if(instance == nullptr) {
                instance = new GPIO();
            }
            return instance;
        }

        void initGPIO(const std::string& PIN, int mode) {
            if(mode == 1) {
                if(!isInput) {
                    std::cout << PIN << " la ngo vao" << std::endl;
                    isInput = true;
                } else {
                    std::cout << "Da khoi tao ngo vao" << std::endl;
                }
            }
            if(mode == 0) {
                if(!isOutput) {
                    std::cout << PIN << " la ngo ra" << std::endl;
                    isOutput = true;
                } else {
                    std::cout << "Da khoi tao ngo ra" << std::endl;
                }
            }
        }

};

GPIO* GPIO::instance = nullptr;

int main() {
    GPIO* gpio = GPIO::getInstance();
    GPIO* gpio1 = GPIO::getInstance();
    gpio->initGPIO("PIN_B0", 0);
    gpio->initGPIO("PIN_B1", 1);
    gpio1->initGPIO("PIN_B2", 0);

    return 0;
}