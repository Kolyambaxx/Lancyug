// Lancyug.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Handler {
public:
    Handler(Handler* nextHandler) : nextHandler(nextHandler) {}

    
    virtual void handleRequest(int request) const = 0;

    
    void passToNextHandler(int request) const {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }

private:
    Handler* nextHandler;
};


class ConcreteHandler1 : public Handler {
public:
    ConcreteHandler1(Handler* nextHandler) : Handler(nextHandler) {}

    void handleRequest(int request) const override {
        if (request >= 0 && request < 10) {
            std::cout << "Concrete Handler 1: Handling request " << request << std::endl;
        }
        else {
            passToNextHandler(request);
        }
    }
};


class ConcreteHandler2 : public Handler {
public:
    ConcreteHandler2(Handler* nextHandler) : Handler(nextHandler) {}

    void handleRequest(int request) const override {
        if (request >= 10 && request < 20) {
            std::cout << "Concrete Handler 2: Handling request " << request << std::endl;
        }
        else {
            passToNextHandler(request);
        }
    }
};


int main() {
  
    Handler* handlerChain = new ConcreteHandler1(new ConcreteHandler2(nullptr));

    
    handlerChain->handleRequest(5);   
    handlerChain->handleRequest(15);  
    handlerChain->handleRequest(25);  

    
    delete handlerChain;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
