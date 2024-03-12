
#include <iostream>
#include <vector>

using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister();
    cashRegister(int cashIn);
    int getCurrentBalance();
    void acceptAmount(int amountIn);

};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType();
    dispenserType(int setNumberOfItems, int setTypeCost);
    int getNoOfItems();
    int getCost();
    void makeSale();
};

cashRegister::cashRegister() {
    cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn) {
    cashOnHand = cashIn;
}

int cashRegister::getCurrentBalance() {
    return cashOnHand;

}

void cashRegister::acceptAmount(int amountIn) {
    cashOnHand = cashOnHand + amountIn;
}

dispenserType::dispenserType() {
    numberOfItems = 50;
    cost = 50;
}

dispenserType::dispenserType(int setNumberOfItems, int setCost) {
    numberOfItems = setNumberOfItems;
    cost = setCost;
}

int dispenserType::getNoOfItems() {
    return numberOfItems;
}

int dispenserType::getCost() {
    return cost;
}

void dispenserType::makeSale() {
    numberOfItems--;
}

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);
int main() {
    setlocale(LC_ALL, "Russian");
    cashRegister counter;
    dispenserType candy(100, 50);
    dispenserType chips(70, 60);
    dispenserType gum(80, 65);
    dispenserType cookies(100, 60);
    int choice;
    showSelection();
    cin >> choice;
    while (choice != 5) {
        switch (choice) {
        case 1:
            sellProduct(candy, counter);
            break;
        case 2:
            sellProduct(chips, counter);
            break;
        case 3:
            sellProduct(gum, counter);
        case 4:
            sellProduct(cookies, counter);
        default:
            cout << "Неверный выбор." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}

void showSelection() {
    cout << "*** Приветствуем вас ***" << endl;
    cout << "Выберите товар " << endl;
    cout << "1 - конфеты" << endl;
    cout << "2 - чипсы" << endl;
    cout << "3 - жвачка" << endl;
    cout << "4 - печенье" << endl;
    cout << "5 - выход" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
    int amount; //переменная для хранения введенной суммы
    int amount2; //переменная для хранения необходимой дополнительной суммы
    if (product.getNoOfItems() > 0) //если раздатчик не пуст
    {
        cout << "Пожалуйста, оплатите покупку " << product.getCost() << " рубли" << endl;
        cin >> amount;
        if (amount < product.getCost())
        {
            cout << "Пожалуйста, внесите недостающую сумму " << product.getCost() - amount << " рубли" << endl;
            cin >> amount2;
            amount = amount + amount2;
        }

        if (amount > product.getCost())
        {
            cout << "Пожалуйста, возьмите сдачу " << amount - product.getCost() << " рубли" << endl;
            amount = amount - product.getCost();
        }
        
        if (amount = product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Заберите вашу покупку" << endl;
        }

        else
            cout << "Недостаточно средств. " << "Заберите вашу сумму." << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }
    else
        cout << "Извините, товар закончился." << endl;
}
         if (amount > product.getCost()) 
         {
             pCounter.acceptAmount(amount);
             product.makeSale();
             cout << "Заберите сдачу" << endl;
         }

         
 

        
