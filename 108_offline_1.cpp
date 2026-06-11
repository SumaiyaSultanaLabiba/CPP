#include<iostream>
using namespace std;


class Fraction
{
  private:
    int numerator;
    int denominator;

  public:

    //Default Constructor
     Fraction()
     {
      this->numerator=0;
      this->denominator=1;
     }

     // Constructor with Single Integer
     Fraction(int n)
     {
      this->numerator=n;
      this->denominator=1;
     }

     //Constructor with Two Integers
     Fraction(int n, int d)
     {
      if(n==0||d==0)
      {
        this->numerator=0;
        this->denominator=1;
      }

    else
      {
      bool flag=false;
      if(n>0&&d<0||n<0&&d>0) flag=true;
      if(n<0) n=-n;
      if(d<0) d=-d;
      int smaller=(n>=d)? d:n;
      int greater=(n<d)? d:n;
      int gcd;//gcd of n and d
      while(1)
      {
        int save_smaller=smaller;
        int save_greater=greater;
        if(greater%smaller==0) break;
        greater=save_smaller;
        smaller=save_greater%save_smaller;
      }
      gcd=smaller;
      this->numerator=n/gcd;
      this->denominator=d/gcd;
      if(flag==true) this->numerator=-this->numerator;
    }
     }
    
     //Destructor 
     ~Fraction()
     {
      ;
     }

     //Addition (add) with another fraction
     Fraction add(Fraction &f)
     {
       int lcm;
       int factor=1;
       int smaller=(this->denominator>=f.denominator)? f.denominator:this->denominator;
       int greater=(this->denominator<f.denominator)? f.denominator:this->denominator;
       while(1)
       {
        if((greater*factor)%smaller==0) break;
        else factor++;
       }
       lcm=greater*factor;
       int result_denominator=lcm;
       int result_numerator=(lcm/this->denominator)*this->numerator+(lcm/f.denominator)*f.numerator;
       return Fraction(result_numerator, result_denominator);
     }



     //Addition (add) with an integer
     Fraction add(int n)
     {
       Fraction other(n);
       return this->add(other);
     }



      //Subtract another fraction
      Fraction sub(Fraction &f)
      {
        //calculating LCM of denominators of two fractions
        int lcm;
        int factor=1;
        int smaller=(this->denominator>=f.denominator)? f.denominator:this->denominator;
        int greater=(this->denominator<f.denominator)? f.denominator:this->denominator;
        while(1)
        {
         if((greater*factor)%smaller==0) break;
         else factor++;
        }
        lcm=greater*factor;
 
        Fraction result((lcm/this->denominator)*this->numerator-(lcm/f.denominator)*f.numerator, lcm);
        return result;
      }
 
 
 
      //Subtract an integer
      Fraction sub(int n)
      {
       Fraction other(n);
       return this->sub(other);
      }
      

      //Multiplication with another fraction
      Fraction mul(Fraction &f)
      {
        Fraction result(this->numerator*f.numerator, this->denominator*f.denominator);
        return result;
      }

      //Multiplication with an integer
      Fraction mul(int n)
      {
       Fraction other(n);
       return this->mul(other);
      }

      //Division by another fraction
      Fraction div(Fraction &f)
      {
        if(f.numerator==0) 
        {
          cout<<" Can not divide by 0 "<<endl;
          return Fraction(this->numerator, this->denominator);
        }
        else
        {
        Fraction result(this->numerator*f.denominator, this->denominator*f.numerator);
        return result;
        }
      }


      //Division by an integer
      Fraction div(int n)
      {
       Fraction other(n);
       return this->div(other);
      }

      //Print
      void print()
      {
        cout<<this->numerator<<"/"<<this->denominator<<endl;
      }

      int get_numerator()
      {
        return this->numerator;
      }

      bool is_equal(Fraction f)
      {
        if(this->numerator==f.numerator&&this->denominator==f.denominator)
        {
          return true;
        }
        else return false;
      }

};



class FractionCollection: public Fraction 
{
  private:
    Fraction* fractions;
    int maxlength;//how much memory is allocated for fractions array
    int length;//how many elements are actually present

  public:
    //Default Constructor
    FractionCollection()
    {
      maxlength=10;
      length=0;//because currently there is no element
      fractions=new Fraction[10];
    }


    //Constructor with Maximum Size
    FractionCollection(int maxsize)
    {
      maxlength=maxsize;
      length=0;//because currently there is no element
      fractions=new Fraction[maxsize];
    }


    //Destructor
    ~FractionCollection()
    {
      delete[] fractions;
    }


    //Insert at the last position
    void insert(Fraction f)
    {
      fractions[length]=f;
      length++;
    }


    //Insert at a specific position
    void insert(int pos, Fraction f)
    {
      for(int i=length-1; i>=pos; i--)
      {
        fractions[i+1]=fractions[i];
      }
      fractions[pos]=f;
      length++;
    }

    //remove the last element
    void remove()
    {
      length--;
    }


    //remove a specific element
    void remove(Fraction f)
    {
      int pos;//where the f fraction is found
      for(pos=0; pos<length; pos++)
      {
        if(fractions[pos].is_equal(f)) break;
      }
      for(int i=pos+1; i<length; i++)
      {
        fractions[i-1]=fractions[i];
      }
      length--;
    }

    //remove an element from a specific position
    void remove(int pos)
    {
      for(int i=pos+1; i<length; i++)
      {
        fractions[i-1]=fractions[i];
      }
      length--;
    }


    //Getmax
    Fraction getmax()
    {
      Fraction max=fractions[0];
      for(int i=1; i<length; i++)
      {
        if((max.sub(fractions[i])).get_numerator()<0) max=fractions[i];
      }
      return max;
    }

    //Getmin
    Fraction getmin()
    {
      Fraction min=fractions[0];
      for(int i=1; i<length; i++)
      {
        if(min.sub(fractions[i]).get_numerator()>0)
        {
          min=fractions[i];
        }
      }
      return min;
    }


    //Addition within a specified range
    Fraction add(int start, int end)
    {
      Fraction sum;
      for(int i=start; i<=end; i++)
      {
        sum=sum.add(fractions[i]);
      }
      return sum;
    }


    //Multiplication within a specified range
    Fraction mul(int start, int end)
    {
      Fraction product(1);
      for(int i=start; i<=end; i++)
      {
        product=product.mul(fractions[i]);
      }
      return product;
    }

    //Subtract two fractions
    Fraction sub(int pos1, int pos2)
    {
      Fraction result;
      result=fractions[pos1].sub(fractions[pos2]);
      return result;
    }



    //Divide two fractions
    Fraction div(int pos1, int pos2)
    {
      Fraction result;
      result=fractions[pos1].div(fractions[pos2]);
      return result;
    }

    void print()
    {
      cout<<endl;
      cout<<"Fractions"<<endl; 
      cout<<"-------------------------------"<<endl; 
      for(int i=0; i<length; i++)
      {
        cout<<"Fraction "<<i<<":  ";
        fractions[i].print();
      }
      cout<<"Max: ";
      this->getmax().print();
      cout<<"Min: ";
      this->getmin().print();
      cout<<"Summation: ";
      this->add(0, length-1).print();
      cout<<"Multiplication: ";
      this->mul(0, length-1).print();
    }

    int get_length()
    {
      return this->length;
    }

};




int main(){ 
  //create Fraction with numerator, denominator 
  Fraction a(5,2),b(7,2),c(9,2),d(28,5); 
  cout<<"Fraction"<<endl; 
  cout<<"-------------------------------"<<endl; 
  cout<<"A: "; 
  a.print(); 
  cout<<"B: "; 
  b.print(); 
  cout<<endl; 

  cout<<"Add(a,b): "; 
  a.add(b).print(); 
  cout<<"Add(a,2): "; 
  a.add(2).print(); 
   
  cout<<"Sub(a,b) "; 
  a.sub(b).print(); 
  cout<<"Sub(a,2) "; 
  a.sub(2).print(); 
   
  cout<<"Mul(a,b): "; 
  a.mul(b).print(); 
  cout<<"Mul(a,2): "; 
  a.mul(2).print(); 
   
  cout<<"Div(a,b): "; 
  a.div(b).print(); 
  cout<<"Div(a,2): "; 
  a.div(2).print(); 
  cout<<"Div(a,0): "; 
  a.div(0).print(); 

  //Collection of Fractions 
  Fraction e,f(5),g(10); 
  FractionCollection fc(10); 
  fc.insert(a); 
  fc.insert(b); 
  fc.insert(c); 
  fc.print(); 

  cout<<"Sub(Pos0, Pos1): "; 
  fc.sub(0,1).print(); //subtracts the fraction at pos1 from fraction at pos0 
  cout<<"Div(Pos0, Pos1): "; 
  fc.div(0,1).print(); //divides the fraction at pos0 by the fraction at pos1 

  fc.remove(1);  //removed 'b' 
  fc.print();  

  fc.remove(a); 
  fc.print();  

  fc.insert(d); 
  fc.insert(0,e);  //insert at pos0 
  fc.insert(f); 
  fc.insert(g); 
  fc.print(); 

  fc.remove(); //removed the last fraction 
  fc.print();  //notice the output 
       
  return 0; 
}