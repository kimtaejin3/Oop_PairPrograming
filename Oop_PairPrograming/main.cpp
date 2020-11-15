#include<iostream>

using namespace std;

enum BeverageSize {
    TALL = 0,
    GRANDE = 1,
    VENTI = 2,
};

class Beverage {
private:
    BeverageSize size;
public:
    string description = "Unknown Beverage";

    virtual string getDescription() {
        return description;
    }

    void setSize(BeverageSize newSize) {
        this->size = newSize;
    }

    virtual BeverageSize getSize() {
        return this->size;
    }

    virtual double cost() = 0;

    virtual void toString() {
        cout << "< BEVERAGE INFORMATION > " << endl;
        cout << "MENU : " << getDescription() << endl;
        switch (getSize()) {
        case TALL:
            cout << "SIZE : TALL" << endl;
            break;
        case GRANDE:
            cout << "SIZE : GRANDE" << endl;
            break;
        case VENTI:
            cout << "SIZE : VENTI" << endl;
            break;
        }
        cout << "PRICE : " << cost() << endl;
        cout << "" << endl;
    }
};

class DarkRoast : public Beverage {
public:
    DarkRoast(BeverageSize size) {
        description = "Dark Roast";
        setSize(size);
    }

    double cost() {
        return .99;
    }
};

class Decaf : public Beverage {
public:
    Decaf(BeverageSize size) {
        description = "Decaf Coffee";
        setSize(size);
    }

    double cost() {
        return 1.05;
    }
};

class Espresso : public Beverage {
public:
    Espresso(BeverageSize size) {
        description = "Espresso";
        setSize(size);
    }
    double cost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend(BeverageSize size) {
        description = "HouseBlend";
        setSize(size);
    }
    double cost() {
        return .89;
    }


};


class CondimentDecorator : public Beverage {
public:
    Beverage* beverage;
    virtual string getDescription() = 0;
};

class Milk : public CondimentDecorator {
public:
    Milk(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return beverage->getDescription() + ", Milk";
    }

    BeverageSize getSize() {
        return beverage->getSize();
    }

    double cost() {
        if (beverage->getSize() == TALL) {
            return .20 + beverage->cost();
        }
        else if (beverage->getSize() == GRANDE) {
            return .25 + beverage->cost();
        }
        else if (beverage->getSize() == VENTI) {
            return .30 + beverage->cost();
        }
        else {
            return 0.0;
        }
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return beverage->getDescription() + ", Mocha";
    }

    BeverageSize getSize() {
        return beverage->getSize();
    }

    double cost() {
        if (beverage->getSize() == TALL) {
            return .10 + beverage->cost();
        }
        else if (beverage->getSize() == GRANDE) {
            return .15 + beverage->cost();
        }
        else if (beverage->getSize() == VENTI) {
            return .20 + beverage->cost();
        }
        else {
            return 0.0;
        }
    }
};

class Soy : public CondimentDecorator {
public:
    Soy(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return beverage->getDescription() + ", Soy";
    }

    BeverageSize getSize() {
        return beverage->getSize();
    }

    double cost() {
        if (beverage->getSize() == TALL) {
            return .5 + beverage->cost();
        }
        else if (beverage->getSize() == GRANDE) {
            return .10 + beverage->cost();
        }
        else if (beverage->getSize() == VENTI) {
            return .15 + beverage->cost();
        }
        else {
            return 0.0;
        }
    }
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() {
        return beverage->getDescription() + ", Whip";
    }

    BeverageSize getSize() {
        return beverage->getSize();
    }

    double cost() {
        if (beverage->getSize() == TALL) {
            return .5 + beverage->cost();
        }
        else if (beverage->getSize() == GRANDE) {
            return .10 + beverage->cost();
        }
        else if (beverage->getSize() == VENTI) {
            return .15 + beverage->cost();
        }
        else {
            return 0.0;
        }
    }
};

int main() {
    Beverage* bever1 = new Espresso(TALL);

    bever1->toString();

    Beverage* bever2 = new DarkRoast(GRANDE);
    bever2 = new Mocha(bever2);
    bever2 = new Mocha(bever2);
    bever2 = new Whip(bever2);

    bever2->toString();

    Beverage* bever3 = new HouseBlend(VENTI);
    bever3 = new Soy(bever3);
    bever3 = new Mocha(bever3);
    bever3 = new Whip(bever3);

    bever3->toString();

    return 0;
}
