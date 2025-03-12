#include <iostream>
#include <string>

using namespace std;
 
class Pizza{
    public:
        virtual double cost() const = 0;
        virtual ~Pizza() = default;
};

class PizzaStore{
    public:
        virtual Pizza* orderPizza(const string& item) const = 0;
};

class NYCheesePizza: public Pizza{
    public:
        NYCheesePizza(){
            cout << "NY Pizza : Cheese pizza : ";
        }
        double cost() const override{
            return 10.99;
        }
};

class NYPepperoniPizza: public Pizza{
    public:
        NYPepperoniPizza(){
            cout << "NY Pizza : Pepperoni pizza : ";
        }

        double cost() const override{
            return 9.89;
        }
};

class NYPizzaStore: public PizzaStore{
    public:
        Pizza* orderPizza(const string& item) const override{
            if(item == "cheese"){
                return new NYCheesePizza();
            }else if(item == "pepperoni"){
                return new NYPepperoniPizza();
            }
            return nullptr;
        }
};

class ChicagoCheesePizza: public Pizza{
    public:
        ChicagoCheesePizza(){
            cout << "Chicago Pizza : Cheese pizza : ";
        }
        double cost() const override{
            return 11.99;
        }
};

class ChicagoPepperoniPizza: public Pizza{
    public:
        ChicagoPepperoniPizza(){
            cout << "Chicago Pizza : Pepperoni pizza : ";
        }

        double cost() const override{
            return 12.99;
        }
};

class ChicagoPizzaStore: public PizzaStore{
    public:
        Pizza* orderPizza(const string& item) const override{
            if(item == "cheese"){
                return new ChicagoCheesePizza();
            }else if(item == "pepperoni"){
                return new ChicagoPepperoniPizza();
            }
            return nullptr;
        }
};

int main(){

    PizzaStore* nyStore = new NYPizzaStore();
    PizzaStore* chicagoStore = new ChicagoPizzaStore();
    
    Pizza* pizza = nyStore -> orderPizza("cheese");
    if(pizza){
        cout << "$" << pizza->cost() << endl;
        delete pizza;
    }

    pizza = nyStore -> orderPizza("pepperoni");
    if(pizza){
        cout << "$" << pizza->cost() << endl;
        delete pizza;
    }

    pizza = chicagoStore -> orderPizza("cheese");
    if(pizza){
        cout << "$" << pizza->cost() << endl;
        delete pizza;
    }

    pizza = chicagoStore -> orderPizza("pepperoni");
    if(pizza){
        cout << "$" << pizza->cost() << endl;
        delete pizza;
    }

    delete nyStore;
    delete chicagoStore;

    return 0;
}