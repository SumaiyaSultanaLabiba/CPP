#include<iostream>
#include<cstring>
using namespace std;

class Product
{
private:
string productName;
string productID;
double price;
int stockChanges[100];
int numStockChanges;

public:

///////////////////////////////////////////////////
Product()
{
    this->productName="Unnamed";
    this->productID="Unknown";
    this->price=0;
    this->numStockChanges=0;
    this->stockChanges[0]=0;
}

///////////////////////////////////////////////////
Product(string productName, string productID, double price)
{
    this->productName=productName;
    this->productID=productID;
    this->price=price;
    this->numStockChanges=0;
    this->stockChanges[0]=0;
}

///////////////////////////////////////////////////
void addStock(int amount)
{
    if(this->numStockChanges==100)
    {
        cout<<"Cannot save any more stock change."<<endl;
        return ;
    }
    if(this->numStockChanges>0) this->stockChanges[this->numStockChanges]=this->stockChanges[this->numStockChanges-1]+amount;
    else this->stockChanges[this->numStockChanges]=amount;
    this->numStockChanges++;
}

//////////////////////////////////////////////////
void reduceStock(int amount)
{
    if(this->numStockChanges==100)
    {
        cout<<"Cannot save any more stock change."<<endl;
        return ;
    }
    if(this->numStockChanges>0) this->stockChanges[this->numStockChanges]=this->stockChanges[this->numStockChanges-1]-amount;
    else this->stockChanges[this->numStockChanges]=amount;
    this->numStockChanges++;
}

/////////////////////////////////////////////////
int getCurrentStock()
{
    if(this->numStockChanges!=0) return this->stockChanges[this->numStockChanges-1];
    else return this->stockChanges[this->numStockChanges];
}

////////////////////////////////////////////////
void display()
{
    cout<<"Product: "<<this->productName<<" (ID: "<<this->productID<<"), Price: Tk."<<this->price<<", Stock: ";
    if(this->numStockChanges!=0) cout<<this->stockChanges[this->numStockChanges-1]<<endl;
    else cout<<this->stockChanges[this->numStockChanges]<<endl;
}

/////////////////////////////////////////////////
string getID()
{
    return this->productID;
}

/////////////////////////////////////////////////
int getNumStockChanges()
{
   return this->numStockChanges;
}
};


class Inventory
{
private:
Product* products;
int numProducts;
int maxProducts;

public:
//////////////////////////////////////////////////
Inventory()
{
    this->numProducts=0;
    this->maxProducts=10;
    this->products=new Product[this->maxProducts];
}

/////////////////////////////////////////////////
Inventory(int maxProducts)
{
    this->numProducts=0;
    this->maxProducts=maxProducts;
    this->products=new Product[this->maxProducts];
}

/////////////////////////////////////////////////
Inventory(Product* products, int numProducts, int maxProducts)
{
    this->numProducts=numProducts;
    this->maxProducts=maxProducts;
    this->products=new Product[this->maxProducts];
    for(int i=0; i<numProducts; i++)
    {
        this->products[i]=products[i];
    }
}

////////////////////////////////////////////////
Inventory(const Inventory& other)
{
    this->numProducts=other.numProducts;
    this->maxProducts=other.maxProducts;
    this->products=new Product[this->maxProducts];
    for(int i=0; i<this->numProducts; i++)
    {
        this->products[i]=other.products[i];
    }
}

/////////////////////////////////////////////////
~Inventory()
{
    delete[] this->products;
}

/////////////////////////////////////////////////
void addProduct(Product p)
{
    if(this->maxProducts==this->numProducts)
    {
        cout<<"Inventory full. Cannot add any more product."<<endl;
        return;
    }
    this->products[this->numProducts]=p;
    this->numProducts++;
    cout<<"Product added with ID: "<<p.getID()<<endl;
}

/////////////////////////////////////////////////
void updateProductStock(string productID, int amount)
{
    int i;
    for(i=0; i<this->numProducts; i++)
    {
        if(this->products[i].getID()==productID)
        break;
    }
    if(i==this->numProducts)
    {
        cout<<"Product not found."<<endl;
    }
    else
    {
        if(amount>=0) this->products[i].addStock(amount);
        if(amount<0) this->products[i].reduceStock(-amount);
    }
}

/////////////////////////////////////////////////////////
void listAllProducts()
{
    for(int i=0; i<this->numProducts; i++)
    {
        this->products[i].display();
    }
}

/////////////////////////////////////////////////////
Product getMostStockedProduct()
{
    int highestCurrentStock=0;
    Product productWithhighestCurrentStock;
    for(int i=0; i<this->numProducts; i++)
    {
        if(this->products[i].getCurrentStock()>highestCurrentStock)
        {
            highestCurrentStock=this->products[i].getCurrentStock();
            productWithhighestCurrentStock=this->products[i];
        }
        if(this->products[i].getCurrentStock()==highestCurrentStock && this->products[i].getNumStockChanges()<productWithhighestCurrentStock.getNumStockChanges())
        {
            highestCurrentStock=this->products[i].getCurrentStock();
            productWithhighestCurrentStock=this->products[i];
        }
    }
    return productWithhighestCurrentStock;
}
};

int main() { 
Inventory inv1(5); 
Product p1("Laptop", "P001", 50000); 
Product p2("Smartphone", "P002", 30000); 
Product p3("Tablet", "P003", 25000); 
Product p4("Smartwatch", "P004", 4000); 
Product p5("Headphones", "P005", 2000); 
Product p6("Charger", "P006", 1000); 
inv1.addProduct(p1); 
inv1.addProduct(p2); 
inv1.addProduct(p3); 
inv1.addProduct(p4); 
inv1.addProduct(p5); 
inv1.addProduct(p6); 
inv1.updateProductStock("P001", 50); 
inv1.updateProductStock("P001", -10); 
inv1.updateProductStock("P003", 70); 
inv1.updateProductStock("P002", 70); 
inv1.updateProductStock("P002", -5); 
inv1.updateProductStock("P003", -10); 
cout << "\nProducts in Inventory 1:\n"; 
inv1.listAllProducts(); 
cout << "\nMost Stocked Product in Inventory 1:\n"; 
inv1.getMostStockedProduct().display(); 
Inventory inv2 = inv1; 
inv2.updateProductStock("P003", 10); 
inv2.updateProductStock("P002", 10); 
inv2.updateProductStock("P002", -5); 
cout << "\nProducts in Inventory 2:\n"; 
inv2.listAllProducts(); 
cout << "\nMost Stocked Product in Inventory 1:\n"; 
inv1.getMostStockedProduct().display(); 
cout << "\nMost Stocked Product in Inventory 2:\n"; 
inv2.getMostStockedProduct().display(); 
return 0; 
}