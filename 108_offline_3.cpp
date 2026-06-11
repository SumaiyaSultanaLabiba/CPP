#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


class Fraction
{
    private:
    int numerator;
    int denominator;


    public:
    //default constructor
    Fraction()
    {
        this->numerator=0;
        this->denominator=1;
    }


    //parameterized constructor
    Fraction(int numerator, int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }


    //Reduction to the simpliest form
    Fraction reduce_to_simplified_form() const
    {
      int numerator=this->numerator;
      int denominator=this->denominator;

      if(numerator==0||denominator==0)
      {
        return Fraction(0, 1);//converts all zero and inavlid inputs into 0/1 fraction
      }

      else
      {
        bool need_to_put_minus=false;
        if((numerator>0&&denominator<0) || (numerator<0&&denominator>0))
        {
            need_to_put_minus=true;
            if(numerator<0) numerator=-numerator;
            if(denominator<0) denominator=-denominator;
        }

        int numerator_copy=numerator;
        int denominator_copy=denominator;
        int gcd=1;
        int temp=1;
        while(numerator_copy%denominator_copy!=0)
        {
            temp=denominator_copy;
            denominator_copy=numerator_copy%denominator_copy;
            numerator_copy=temp;
        }
        gcd=denominator_copy;
        if(need_to_put_minus)
        {
            return Fraction(-numerator/gcd, denominator/gcd);
        }
        else
        {
            return Fraction(numerator/gcd, denominator/gcd);
        }
      }
    }


    //Printing fraction with cout<<
    friend ostream& operator<<(ostream& ostream,const Fraction& ob)
    {
        Fraction ob_simplified=ob.reduce_to_simplified_form();
        cout<<ob_simplified.numerator<<"/"<<ob_simplified.denominator;
        return ostream;
    }


    //Fraction + Fraction
    Fraction operator+(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        int numerator=this->numerator*f.denominator+this->denominator*f.numerator;
        int denominator=this->denominator*f.denominator;
        return Fraction(numerator, denominator).reduce_to_simplified_form();
    }

    //Fraction + float
    Fraction operator+(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return *this+Num;
    }

    //Float + fraction
    friend Fraction operator+(const float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return Num+f;
    }


    //Fraction += Fraction
    Fraction operator+=(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        *this=*this+f;
        return *this;
    }


    //Fraction += float
    Fraction operator+=(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction f=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       *this=*this+f;
       return *this;
    }


    //Float += fraction
    friend float operator+=(float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction sum=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       sum=sum+f;
       num=(float)sum.numerator/(float)sum.denominator;
       return num;
    }


    //Fraction - Fraction
    Fraction operator-(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        int numerator=this->numerator*f.denominator-this->denominator*f.numerator;
        int denominator=this->denominator*f.denominator;
        return Fraction(numerator, denominator).reduce_to_simplified_form();
    }

    //Fraction - float
    Fraction operator-(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return *this-Num;
    }

    //Float - fraction
    friend Fraction operator-(const float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return Num-f;
    }


    //Fraction -= Fraction
    Fraction operator-=(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        *this=*this-f;
        return *this;
    }


    //Fraction -= float
    Fraction operator-=(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction f=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       *this=*this-f;
       return *this;
    }


    //Float -= fraction
    friend float operator-=(float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction sum=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       sum=sum-f;
       num=(float)sum.numerator/(float)sum.denominator;
       return num;
    }


    //Fraction * Fraction
    Fraction operator*(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        int numerator=this->numerator*f.numerator;
        int denominator=this->denominator*f.denominator;
        return Fraction(numerator, denominator).reduce_to_simplified_form();
    }

    //Fraction * float
    Fraction operator*(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return *this*Num;
    }

    //Float * fraction
    friend Fraction operator*(const float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return Num*f;
    }


    //Fraction *= Fraction
    Fraction operator*=(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        *this=*this*f;
        return *this;
    }


    //Fraction *= float
    Fraction operator*=(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction f=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       *this=*this*f;
       return *this;
    }


    //Float *= fraction
    friend float operator*=(float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction sum=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       sum=sum*f;
       num=(float)sum.numerator/(float)sum.denominator;
       return num;
    }


    //Fraction / Fraction
    Fraction operator/(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        if(f.numerator==0)
        {
            cout<<"Cannot divide by zero. Returning the dividend: ";
            f.numerator=1;
        }
        int numerator=this->numerator*f.denominator;
        int denominator=this->denominator*f.numerator;
        return Fraction(numerator, denominator).reduce_to_simplified_form();
    }

    //Fraction / float
    Fraction operator/(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return *this/Num;
    }

    //Float / fraction
    friend Fraction operator/(const float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction Num=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       return Num/f;
    }


    //Fraction /= Fraction
    Fraction operator/=(Fraction& f)
    {
        *this=this->reduce_to_simplified_form();
        f=f.reduce_to_simplified_form();
        *this=*this/f;
        return *this;
    }


    //Fraction /= float
    Fraction operator/=(const float& num)
    {
       *this=this->reduce_to_simplified_form();
       Fraction f=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       *this=*this/f;
       return *this;
    }


    //Float /= fraction
    friend float operator/=(float& num, Fraction& f)
    {
       f=f.reduce_to_simplified_form();
       Fraction sum=Fraction(num*1000000, 1000000).reduce_to_simplified_form();
       sum=sum/f;
       num=(float)sum.numerator/(float)sum.denominator;
       return num;
    }


    //Calculating the square root of the fraction
    float square_root()
    {
        float Numerator=sqrt(this->numerator);
        float Denominator=sqrt(this->denominator);
        return Numerator/Denominator;
    }
};


class FractionVector
{
  private:
  int count;//how many fractions are there in the list_of_fractions
  Fraction* list_of_fractions;

  public:
  //default constructor
  FractionVector()
  {
    this->count=1;
    this->list_of_fractions=new Fraction[this->count];
  }


  //parametrized constructor
  FractionVector(int count, Fraction* list)
  {
    this->count=count;
    this->list_of_fractions=new Fraction[this->count];
    for(int i=0; i<count; i++)
    {
      this->list_of_fractions[i]=list[i];
    }
  }


   //Copy constructor
   FractionVector(const FractionVector& vector)
   {
    this->count=vector.count;
    this->list_of_fractions=new Fraction[this->count];
    for(int i=0; i<this->count; i++)
    {
        this->list_of_fractions[i]=vector.list_of_fractions[i];
    }
   }


   //Overloading Assignment '=' operator
   FractionVector operator=(const FractionVector& f)
   {
     delete[] this->list_of_fractions;
     this->count=f.count;
     this->list_of_fractions=new Fraction[this->count];
     for(int i=0; i<this->count; i++)
     {
        this->list_of_fractions[i]=f.list_of_fractions[i];
     }
     return *this;
   }


   //Destructor
   ~FractionVector()
   {
    delete[] this->list_of_fractions;
   }


   //Printing the vector by cout<<
  friend ostream& operator<<(ostream& ostream,const FractionVector& vector)
    {
        cout<<"[";
        for(int i=0; i<vector.count; i++)
        {
            cout<<(vector.list_of_fractions[i]);
            if(i==vector.count-1) continue;
            cout<<", ";
        }
        cout<<"]";
        return ostream;
    }


    //Overloading [] operator to access nth fraction of the vector
    Fraction operator[](int n)
    {
        if(n>this->count)
        {
            return this->list_of_fractions[this->count-1];
        }
        if(n<1)
        {
            return this->list_of_fractions[0];
        }
        return this->list_of_fractions[n-1];
    }


    //Overloading + for element wise vector addition
    FractionVector operator+(const FractionVector& vector)
    {
        if(this->count!=vector.count)
        {
            Fraction f(0, 1);
            Fraction list[1];
            list[0]=f;
            cout<<"Cannot add to vector of different sizes. Returning: ";
            return FractionVector(1, list);
        }
        else
        {
            Fraction list[this->count];
            for(int i=0; i<this->count; i++)
            {
                list[i]=this->list_of_fractions[i]+vector.list_of_fractions[i];
            }
            return FractionVector(this->count, list);
        }
    }


     //Overloading - for element wise vector addition
    FractionVector operator-(const FractionVector& vector)
    {
        if(this->count!=vector.count)
        {
            Fraction f(0, 1);
            Fraction list[1];
            list[0]=f;
            cout<<"Cannot subtract vector of different sizes. Returning: ";
            return FractionVector(1, list);
        }
        else
        {
            Fraction list[this->count];
            for(int i=0; i<this->count; i++)
            {
                list[i]=this->list_of_fractions[i]-vector.list_of_fractions[i];
            }
            return FractionVector(this->count, list);
        }
    }


    //Overloading % for element wise vector multiplication
    FractionVector operator%(const FractionVector& vector)
    {
        if(this->count!=vector.count)
        {
            Fraction f(0, 1);
            Fraction list[1];
            list[0]=f;
            cout<<"Cannot elementwise mutiply vector of different sizes. Returning: ";
            return FractionVector(1, list);
        }
        else
        {
            Fraction list[this->count];
            for(int i=0; i<this->count; i++)
            {
                list[i]=this->list_of_fractions[i]*vector.list_of_fractions[i];
            }
            return FractionVector(this->count, list);
        }
    }


    //Overloading FractionVector*fraction
    FractionVector operator*(Fraction& f)
    {
        Fraction list[this->count];
        for(int i=0; i<this->count; i++)
        {
            list[i]=this->list_of_fractions[i]*f;
        }
        return FractionVector(this->count, list);
    }


    //Overloading fraction*FractionVector
    friend FractionVector operator*(Fraction& f, FractionVector& vector)
    {
        Fraction list[vector.count];
        for(int i=0; i<vector.count; i++)
        {
            list[i]=f*vector.list_of_fractions[i];
        }
        return FractionVector(vector.count, list);
    }


       //Overloading FractionVector/fraction
    FractionVector operator/(Fraction& f)
    {
        Fraction list[this->count];
        for(int i=0; i<this->count; i++)
        {
            list[i]=this->list_of_fractions[i]/f;
        }
        return FractionVector(this->count, list);
    }


    //Overloading fraction/FractionVector
    friend FractionVector operator/(Fraction& f, FractionVector& vector)
    {
        Fraction list[vector.count];
        for(int i=0; i<vector.count; i++)
        {
            list[i]=f/vector.list_of_fractions[i];
        }
        return FractionVector(vector.count, list);
    }


    //Dot product
    Fraction operator*(const FractionVector& vector)
    {
        Fraction result(0, 1);
        Fraction temp(0, 1);
        if(this->count==vector.count)
        {
            for(int i=0; i<this->count; i++)
            {
                temp=this->list_of_fractions[i]*vector.list_of_fractions[i];
                result+=temp;
            }
        }
        else
        {
            cout<<"Cannot dot product between two vectors of different length. Returning: 0/1"<<endl;
        }
        return result;
    }


    //Calculating the magnitude of the vector
    float value()
    {
        Fraction square_value(0, 1);
        Fraction temp(0, 1);
        for(int i=0; i<this->count; i++)
        {
          temp=this->list_of_fractions[i]*this->list_of_fractions[i];
          square_value+=temp;
        }
        return square_value.square_root();
    }

};



class FractionMatrix
{
   private:
   int number_of_rows;
   int number_of_columns;
   FractionVector* rows;
   FractionVector* columns;

   public:
   //default constructor
   FractionMatrix()
   {
     this->number_of_rows=1;
     this->number_of_columns=1;
     this->rows=new FractionVector[this->number_of_rows];
     this->columns=new FractionVector[this->number_of_columns];
   }


   //parameterized constructor
   FractionMatrix(int nr, int nc, FractionVector* rows, FractionVector* columns)
   {
     this->number_of_rows=nr;
     this->number_of_columns=nc;
     this->rows=new FractionVector[this->number_of_rows];
     this->columns=new FractionVector[this->number_of_columns];
     for(int i=0; i<nr; i++)
     {
        this->rows[i]=rows[i];
     }
     for(int j=0; j<nc; j++)
    {
        Fraction* list=new Fraction[nr];
        for(int i=0; i<nr; i++)
        {
            list[i]=(*this)[i+1][j+1];
        }
        FractionVector temp(nr, list);
        this->columns[j]=temp;
        delete[] list;
    }
   }


   //Copy constructor
   FractionMatrix(const FractionMatrix& matrix)
   {
     this->number_of_rows=matrix.number_of_rows;
     this->number_of_columns=matrix.number_of_columns;
     this->rows=new FractionVector[this->number_of_rows];
     for(int i=0; i<matrix.number_of_rows; i++)
     {
        this->rows[i]=matrix.rows[i];
     }
     this->columns=new FractionVector[this->number_of_columns];
     for(int i=0; i<matrix.number_of_columns; i++)
     {
        this->columns[i]=matrix.columns[i];
     }
   }


   //overloading assignment operator '=' for Matrix
   FractionMatrix operator=(const FractionMatrix& matrix)
   {
    delete[] this->rows;
    delete[] this->columns;
    this->number_of_rows=matrix.number_of_rows;
    this->number_of_columns=matrix.number_of_columns;
    this->rows=new FractionVector[this->number_of_rows];
    for(int i=0; i<this->number_of_rows; i++)
    {
        this->rows[i]=matrix.rows[i];
    }
    this->columns=new FractionVector[this->number_of_columns];
    for(int i=0; i<this->number_of_columns; i++)
    {
        this->columns[i]=matrix.columns[i];
    }
    return *this;
   }

   //Destructor
   ~FractionMatrix()
   {
    delete[] this->rows;
    delete[] this->columns;
   }


   //Printing FractionMatrix objects
   friend ostream& operator<<(ostream& ostream, const FractionMatrix& matrix)
   {
    for(int i=0; i<matrix.number_of_rows; i++)
    {
        cout<<matrix.rows[i];
        cout<<endl;
    }
    return ostream;
   }


   //Returning n-th row of the matrix
   FractionVector operator[](int n)
   {
    if(n>this->number_of_rows)
    {
        return this->rows[this->number_of_rows-1];
    }
    else if(n<1)
    {
        return this->rows[0];
    }
    return this->rows[n-1];
   }


   //Get_Column method
   FractionVector getColumn(int index)
   {
     if(index>this->number_of_columns)
    {
        return this->columns[this->number_of_columns-1];
    }
    else if(index<1)
    {
        return this->columns[0];
    }
    return this->columns[index-1];
   }


   //Matrix+Matrix
   FractionMatrix operator+(const FractionMatrix& matrix)
   {
    FractionMatrix result_matrix(*this);
    if(result_matrix.number_of_rows!=matrix.number_of_rows || result_matrix.number_of_columns!=matrix.number_of_columns)
    {
      cout<<"Cannot add two matrices with different dimensions. Returning the first matrix."<<endl;
      return result_matrix;
    }
    for(int i=0; i<result_matrix.number_of_rows; i++)
    {
        result_matrix.rows[i]=result_matrix.rows[i]+matrix.rows[i];
    }
    for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
    return result_matrix;
   }


   //Matrix-Matrix
   FractionMatrix operator-(const FractionMatrix& matrix)
   {
    FractionMatrix result_matrix(*this);
    if(result_matrix.number_of_rows!=matrix.number_of_rows || result_matrix.number_of_columns!=matrix.number_of_columns)
    {
      cout<<"Cannot subtract two matrices with different dimensions. Returning the first matrix."<<endl;
      return result_matrix;
    }
    for(int i=0; i<result_matrix.number_of_rows; i++)
    {
        result_matrix.rows[i]=result_matrix.rows[i]-matrix.rows[i];
    }
    for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
    return result_matrix;
   }


    //Matrix*fraction
    FractionMatrix operator*(Fraction& f)
    {
        FractionMatrix result_matrix(*this);
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            result_matrix.rows[i]=result_matrix.rows[i]*f;
        }
        for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
        return result_matrix;
    }


    //Fraction*Matrix
    friend FractionMatrix operator*(Fraction& f, const FractionMatrix& matrix)
    {
        FractionMatrix result_matrix(matrix);
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            result_matrix.rows[i]=f*result_matrix.rows[i];
        }
        for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
        return result_matrix;
    }


    //Matrix/fraction
    FractionMatrix operator/(Fraction& f)
    {
        FractionMatrix result_matrix(*this);
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            result_matrix.rows[i]=result_matrix.rows[i]/f;
        }
        for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
        return result_matrix;
    }


    //Fraction/Matrix
    friend FractionMatrix operator/(Fraction& f, const FractionMatrix& matrix)
    {
        FractionMatrix result_matrix(matrix);
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            result_matrix.rows[i]=f/result_matrix.rows[i];
        }
        for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
        return result_matrix;
    }


    //Matrix*Matrix
    FractionMatrix operator*(const FractionMatrix& matrix)
    {
        if(this->number_of_columns!=matrix.number_of_rows)
        {
            cout<<"Cannot multiply two matrices when #first_matrix_column!=#second_matrix_row. Returning the first matrix: "<<endl;
            return *this;
        }
        FractionMatrix result_matrix;
        result_matrix.number_of_rows=this->number_of_rows;
        result_matrix.number_of_columns=matrix.number_of_columns;
        result_matrix.rows=new FractionVector[result_matrix.number_of_rows];
        result_matrix.columns=new FractionVector[result_matrix.number_of_columns];

        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
          Fraction list[result_matrix.number_of_columns];
          for(int j=0; j<result_matrix.number_of_columns; j++)
          {
            list[j]=this->rows[i]*matrix.columns[j];
          }  
          FractionVector temp(result_matrix.number_of_columns, list);
          result_matrix.rows[i]=temp;
        }
        for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
        return result_matrix;
    }


   //Elementwise (Hadamard) mulitiplication
   FractionMatrix operator%(const FractionMatrix& matrix)
   {
    FractionMatrix result_matrix(*this);
    if(result_matrix.number_of_rows!=matrix.number_of_rows || result_matrix.number_of_columns!=matrix.number_of_columns)
    {
      cout<<"Cannot multiply(elementwise) two matrices with different dimensions. Returning the first matrix."<<endl;
      return result_matrix;
    }
    for(int i=0; i<result_matrix.number_of_rows; i++)
    {
        result_matrix.rows[i]=result_matrix.rows[i]%matrix.rows[i];
    }
    for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
    return result_matrix;
   }


   //Tranposing a matrix
   FractionMatrix transpose()
   {
    FractionMatrix result_matrix;
    result_matrix.number_of_rows=this->number_of_columns;
    result_matrix.number_of_columns=this->number_of_rows;
    result_matrix.rows=new FractionVector[result_matrix.number_of_rows];
    result_matrix.columns=new FractionVector[result_matrix.number_of_columns];
    for(int i=0; i<result_matrix.number_of_rows; i++)
    {
        result_matrix.rows[i]=this->columns[i];
    }
    for(int i=0; i<result_matrix.number_of_columns; i++)
    {
        result_matrix.columns[i]=this->rows[i];
    }
    for(int j=0; j<result_matrix.number_of_columns; j++)
    {
        Fraction list[result_matrix.number_of_rows];
        for(int i=0; i<result_matrix.number_of_rows; i++)
        {
            list[i]=result_matrix[i+1][j+1];
        }
        FractionVector temp(result_matrix.number_of_rows, list);
        result_matrix.columns[j]=temp;
    }
    return result_matrix;
   }
};



int main()
{
    //Producing 10 fractions, 10 vectors, and 5 matrices for comprehensive illustration of the whole program
    Fraction a(0, 1), b(1, 2), c(2, 3), d(3, 4), e(4, 5), f(5, 6), g(6, 7), h(7, 8), i(8, 9), j(9, 0);
    Fraction list1[3], list2[3], list3[3], list4[4], list5[4], list6[4], list7[4], list8[5], list9[5], list10[5];
    list1[0]=a , list1[1]=b , list1[2]=c ;
    list2[0]=b , list2[1]=c , list2[2]=d ;
    list3[0]=c , list3[1]=d , list3[2]=e ;
    list4[0]=d , list4[1]=e , list4[2]=f , list4[3]=g ;
    list5[0]=e , list5[1]=f , list5[2]=g , list5[3]=h ;
    list6[0]=f , list6[1]=g , list6[2]=h , list6[3]=i ;
    list7[0]=g , list7[1]=h , list7[2]=i , list7[3]=j ;
    list8[0]=h , list8[1]=i , list8[2]=j , list8[3]=a , list8[4]=b ;
    list9[0]=i , list9[1]=j , list9[2]=a , list9[3]=b , list9[4]=c ;
    list10[0]=j , list10[1]=a , list10[2]=b , list10[3]=c , list10[4]=d ;
    FractionVector vector1(3, list1);
    FractionVector vector2(3, list2);
    FractionVector vector3(3, list3);
    FractionVector vector4(4, list4);
    FractionVector vector5(4, list5);
    FractionVector vector6(4, list6);
    FractionVector vector7(4, list7);
    FractionVector vector8(5, list8);
    FractionVector vector9(5, list9);
    FractionVector vector10(5, list10);
    FractionVector rows1[3];
    FractionVector columns1[3];
    FractionVector rows2[3];
    FractionVector columns2[3];
    FractionVector rows3[3];
    FractionVector columns3[4];
    FractionVector rows4[3];
    FractionVector columns4[4];
    FractionVector rows5[4];
    FractionVector columns5[5];
    rows1[0]=vector1 , rows1[1]=vector2 , rows1[2]=vector3 ;
    columns1[0]=vector1 , columns1[1]=vector2 , columns1[2]=vector3 ;
    rows2[0]=vector3 , rows2[1]=vector2 , rows2[2]=vector1 ;
    columns2[0]=vector3 , columns2[1]=vector2 , columns2[2]=vector1 ;
    rows3[0]=vector4 , rows3[1]=vector5 , rows3[2]=vector5 ;
    columns3[0]=vector1 , columns3[1]=vector2 , columns3[2]=vector3 , columns3[3]=vector1 ;
    rows4[0]=vector7 , rows4[1]=vector6 , rows4[2]=vector5 ;
    columns4[0]=vector1 , columns4[1]=vector2 , columns4[2]=vector3 , columns4[3]=vector1 ;
    rows5[0]=vector8 , rows5[1]=vector9 , rows5[2]=vector10 , rows5[3]=vector8 ;
    columns5[0]=vector4 , columns5[1]=vector5 , columns5[2]=vector6 , columns5[3]=vector7 , columns5[4]=vector4 ;
    FractionMatrix matrix1(3, 3, rows1, columns1);
    FractionMatrix matrix2(3, 3, rows2, columns2);
    FractionMatrix matrix3(3, 4, rows3, columns3);
    FractionMatrix matrix4(3, 4, rows4, columns4);
    FractionMatrix matrix5(4, 5, rows5, columns5);


    //Demonstrating all arithmetic and compound assignment operations on Fraction
    cout<<"Printing the first fraction: "<<a<<endl;
    cout<<"Printing the second fraction: "<<b<<endl;
    float num1=1.234;
    float num2=-0.073821;
    cout<<"Fraction+Fraction: "<<a<<"+"<<b<<"="<<a+b<<endl;
    cout<<"Fraction+Float: "<<a<<"+"<<num1<<"="<<a+num1<<endl;
    cout<<"Float+fraction: "<<num1<<"+"<<a<<"="<<num1+a<<endl;
    a+=b;
    cout<<"Fraction+=Fraction: "<<a<<endl;
    a+=num2;
    cout<<"Fraction+=Float: "<<a<<endl;
    num2+=a;
    cout<<"Float+=Fraction: "<<num2<<endl;
    cout<<"******************************"<<endl;
    cout<<"Printing the third fraction: "<<c<<endl;
    cout<<"Printing the fourth fraction: "<<d<<endl;
    float num3=12.234;
    float num4=-5.073821;
    cout<<"Fraction-Fraction: "<<c<<"-"<<d<<"="<<c-d<<endl;
    cout<<"Fraction-Float: "<<c<<"-"<<num3<<"="<<c-num3<<endl;
    cout<<"Float-fraction: "<<num3<<"-"<<c<<"="<<num3-c<<endl;
    c-=d;
    cout<<"Fraction-=Fraction: "<<c<<endl;
    c-=num4;
    cout<<"Fraction-=Float: "<<c<<endl;
    num4-=c;
    cout<<"Float-=Fraction: "<<num4<<endl;
    cout<<"******************************"<<endl;
    cout<<"Printing the fifth fraction: "<<e<<endl;
    cout<<"Printing the sixth fraction: "<<f<<endl;
    float num5=13.0234;
    float num6=5.21;
    cout<<"Fraction*Fraction: "<<e<<"*"<<f<<"="<<e*f<<endl;
    cout<<"Fraction*Float: "<<e<<"*"<<num5<<"="<<e*num5<<endl;
    cout<<"Float*fraction: "<<num5<<"*"<<e<<"="<<num5*e<<endl;
    e*=f;
    cout<<"Fraction*=Fraction: "<<e<<endl;
    e*=num6;
    cout<<"Fraction*=Float: "<<e<<endl;
    num6*=e;
    cout<<"Float*=Fraction: "<<num2<<endl;
    cout<<"******************************"<<endl;
    cout<<"Printing the seventh fraction: "<<g<<endl;
    cout<<"Printing the eighth fraction: "<<h<<endl;
    float num7=1.234;
    float num8=-0.073821;
    cout<<"Fraction/Fraction: "<<g<<"/"<<h<<"="<<g/h<<endl;
    cout<<"Fraction/Float: "<<g<<"/"<<num7<<"="<<g/num7<<endl;
    cout<<"Float/fraction: "<<num7<<"/"<<g<<"="<<num7/g<<endl;
    g/=h;
    cout<<"Fraction/=Fraction: "<<g<<endl;
    g/=num8;
    cout<<"Fraction/=Float: "<<g<<endl;
    num8/=g;
    cout<<"Float/=Fraction: "<<num8<<endl<<endl;

    
    //Demonstrating vector addition, scalar mutiplication, dot product and computing magnitude
    cout<<"Vector1: "<<vector1<<endl;
    cout<<"Vector2: "<<vector2<<endl;
    cout<<"Vector1 + Vector2= "<<vector1+vector2<<endl;
    cout<<"Vector*Fraction: "<<vector1<<"*"<<i<<"= "<<vector1*i<<endl;
    cout<<"Fraction*Vector: "<<i<<"*"<<vector1<<"= "<<i*vector1<<endl;
    cout<<"Vector/Fraction: "<<vector1<<"/ "<<i<<"= "<<vector1/i<<endl;
    cout<<"Dot product: "<<vector1<<"*"<<vector2<<"= "<<vector1*vector2<<endl;
    cout<<"Dot product: "<<vector3<<"*"<<vector4<<"= "<<vector3*vector4<<endl;
    cout<<"Magnitude: |"<<vector5<<"|= "<<vector5.value()<<endl<<endl;


    //Performing matrix addition, scalar multiplication, matrix multiplication, and Hadamard product
    cout<<"First matrix: "<<endl<<matrix1<<endl;
    cout<<"Second matrix: "<<endl<<matrix2<<endl;
    cout<<"Matrix1 + Matrix2: "<<endl<<matrix1+matrix2<<endl;
    cout<<"Third matrix: "<<endl<<matrix3<<endl;
    cout<<"Fifth matrix: "<<endl<<matrix5<<endl;
    cout<<"Matrix3 + Matrix5: "<<endl<<matrix3+matrix5<<endl;
    cout<<"Scalar Multiplication on matrix: "<<endl;
    cout<<matrix1<<"*"<<i<<endl;
    cout<<matrix1*i<<endl;
    cout<<"Matrix4: "<<endl<<matrix4<<endl;
    cout<<"Matrix5: "<<endl<<matrix5<<endl;
    cout<<"Matrix4 * Matrix5: "<<endl<<matrix4*matrix5<<endl;
    cout<<"Matrix3: "<<endl<<matrix3<<endl;
    cout<<"Matrix2: "<<endl<<matrix2<<endl;
    cout<<"Matrix3 * Matrix2: "<<endl<<matrix3*matrix2<<endl;
    cout<<"Hadamard product on matrix1 % matrix2: "<<endl;
    cout<<"First matrix: "<<endl<<matrix1<<endl;
    cout<<"Second matrix: "<<endl<<matrix2<<endl;
    cout<<"Matrix1 % Matrix2: "<<endl<<matrix1%matrix2<<endl;
    return 0;
}
