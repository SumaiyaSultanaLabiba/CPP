#include<iostream>
#include<cstring>
using namespace std;


class Course
{
private:
 string name;//name of the course 
 float creditHour;//number of credit hours assigned  to this course

public:
 Course()
 {
    this->name="Unknown";
    this->creditHour=3.0;
 }

 Course (string name, float creditHour) 
 {
    this->name=name;
    this->creditHour=creditHour;
 } 

 string getName()
 {
    return this->name;
 }

 float getCreditHour()
 {
    return this->creditHour;
 }

 void setName(string name)
 {
    this->name=name;
 }

 void  setCreditHour(float  creditHour)
 {
    this->creditHour=creditHour;
 }

 void display()
 {
    cout<<"Course Name: "<<this->name<<", ";
    cout<<"Credit Hour: "<<this->creditHour;
 }
};



class Student
{
private:
    string name;
    int id;
    Course*  courses;
    int totalCourses;
    int maxCourses;
    float*  gradePoints;

public:
Student()
{
    this->name="Unknown"; 
    this->id=0;
    this->totalCourses=0;
    this->maxCourses=20;
    this->courses=new Course[this->maxCourses];
    this->gradePoints=new float[this->maxCourses];   
}

Student(string  name,  int  id,  int maxCourses)
{
    this->name=name; 
    this->id=id;
    this->totalCourses=0;
    this->maxCourses=maxCourses;
    this->courses=new Course[this->maxCourses];
    this->gradePoints=new float[this->maxCourses];    
}

Student(const Student& ob)
{
    this->name=ob.name; 
    this->id=ob.id;
    this->totalCourses=ob.totalCourses;
    this->maxCourses=ob.maxCourses;
    this->courses=new Course[this->maxCourses];
    for(int i=0; i<ob.maxCourses; i++)
    {
        this->courses[i]=ob.courses[i];
    }
    this->gradePoints=new float[this->maxCourses];
    for(int i=0; i<ob.maxCourses; i++)
    {
        this->gradePoints[i]=ob.gradePoints[i];
    }    
}

~Student()
{
    delete[] this->gradePoints;
    delete[] this->courses;
}

void setName(string name)
{
    this->name=name;
}

void setId(int id)
{
    this->id=id;
}

void  setInfo(string  name,  int  id)
{
    this->name=name;
    this->id=id;
}

void  addCourse(Course  c)
{
  if(this->totalCourses==this->maxCourses)
  {
    cout<<"Cannot add more courses to "<<this->getName()<<endl;
  }  
  else
  {
  this->courses[this->totalCourses]=c;
  this->gradePoints[this->totalCourses]=0;
  totalCourses++;
  }
}

void  addCourse(Course  course,  float  gradePoint)
{
    if(this->totalCourses==this->maxCourses)
    {
      cout<<"Cannot add more courses to "<<this->getName()<<endl;
    }  
    else
    {  
      this->courses[this->totalCourses]=course;
      this->gradePoints[this->totalCourses]=gradePoint;
      totalCourses++;
    }
}

void  setGradePoint (Course  c,  float  gradePoint)
{
    int i=0;
    for(i=0; i<this->totalCourses; i++)
    {
        if(this->courses[i].getName()==c.getName())
        {
            break;
        }
    }
    if(i==this->totalCourses) 
    {cout<<"Not registered in this course.\n"<<endl;}
    else
    {
       this->gradePoints[i]=gradePoint; 
    }
}

void  setGradePoint (float*  gradePoints,  int  n)
{
    for(int i=0; i<n; i++)
    {
        this->gradePoints[i]=gradePoints[i];
    }
}

string getName()
{
    return this->name;
}

float  getCGPA()
{
    float sum_credithour=0;
    float sum_weighted=0;
    for(int i=0; i<this->totalCourses; i++)
    {
        sum_credithour+=this->courses[i].getCreditHour();
    }
    for(int i=0; i<this->totalCourses; i++)
    {
        sum_weighted+=this->courses[i].getCreditHour()*this->gradePoints[i];
    }
    return sum_weighted/sum_credithour;
}

float  getGradePoint (Course  c)
{
    int i=0;
    for(i=0; i<this->totalCourses; i++)
    {
        if(this->courses[i].getName()==c.getName())
        {
            break;
        }
    }
    if(i==this->totalCourses) 
    {
     return 0;
    }
    else
    {
       return this->gradePoints[i]; 
    }    
}

int  getTotalCourses()
{
    return this->totalCourses;
}

float  getTotalCreditHours()
{
    float sum_credithour=0;
    for(int i=0; i<this->totalCourses; i++)
    {
        if(this->gradePoints[i]>=2.00)
        {sum_credithour+=this->courses[i].getCreditHour();}
    }
    return sum_credithour;
}

Course  getMostFavoriteCourse()
{
    int i=0;
    float max_grade=0;
    Course most_favourite_course;
    for(i=0; i<this->totalCourses; i++)
    {
      if(this->getGradePoint(this->courses[i])>max_grade)
      {
        most_favourite_course=this->courses[i];
        max_grade=this->getGradePoint(this->courses[i]);
      }
    }
    return most_favourite_course;
}

Course  getLeastFavoriteCourse()
{
    int i=0;
    float min_grade=4.0;
    Course least_favourite_course;
    for(i=0; i<this->totalCourses; i++)
    {
      if(this->getGradePoint(this->courses[i])<min_grade)
      {
        least_favourite_course=this->courses[i];
        min_grade=this->getGradePoint(this->courses[i]);
      }
    }
    return least_favourite_course;
}

Course*  getFailedCourses(int  &count)
{
  int failed_count=0;
  for(int i=0; i<this->totalCourses; i++)
  {
    if(this->gradePoints[i]<2) failed_count++;
  }
  count=failed_count;
  Course* faliedCourses=new Course[failed_count];
  int index=0;
  for(int i=0; i<this->totalCourses; i++)
  {
    if(this->gradePoints[i]<2)
    {
        faliedCourses[index++]=this->courses[i];
    }
  }
  return faliedCourses;
}

void  display()
{
  int i=0;
  cout<<"=================================="<<endl;
  cout<<"Student Name: "<<this->getName()<<", ID: "<<this->id<<endl;
  for(i=0; i<this->totalCourses; i++)
  {
    this->courses[i].display();  
    cout<<", gradePoint: "<<this->gradePoints[i]<<endl;
  }  
    cout<<"CGPA: "<<this->getCGPA()<<endl;
    cout<<"Total Credit Hours Earned: "<<this->getTotalCreditHours()<<endl;;
    cout<<"Most Favorite Course: "<<this->getMostFavoriteCourse().getName()<<endl;
    cout<<"Least Favorite Course: "<<this->getLeastFavoriteCourse().getName()<<endl;
    cout<<"=================================="<<endl;
}
};


int totalStudents=0;
Student* students[100];

Student  getTopper()
{
    int i=0;
    float max_cgpa=0;
    Student* max_cgpa_holder;
    for(i=0; i<totalStudents; i++)
    {
      if(students[i]->getCGPA()>max_cgpa)
      {
        max_cgpa=students[i]->getCGPA();
        max_cgpa_holder=students[i];
      }
    }
    return *max_cgpa_holder;
}


Student  getTopper(Course  c)
{
    int i=0;
    float max_grade_in_c=0;
    Student* max_grade_holder_in_c=students[0];
    for(i=0; i<totalStudents; i++)
    {
        if(students[i]->getGradePoint(c)>max_grade_in_c)
        {
            max_grade_in_c=students[i]->getGradePoint(c);
        }
    }
    for(i=0; i<totalStudents; i++)
    {
        if(students[i]->getGradePoint(c)==max_grade_in_c)
        {
            max_grade_holder_in_c=students[i];
            break;
        }
    }
    return *max_grade_holder_in_c;
}


int main() { 
    // generate courses 
    const int COURSE_COUNT = 6; 
    Course courses[COURSE_COUNT] = { 
    Course("CSE107", 3), 
    Course("CSE105", 3), 
    Course("CSE108", 1.5), 
    Course("CSE106", 1.5), 
    Course("EEE164", 0.75), 
    Course("ME174", 0.75), 
    }; 
    float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25}; 
    // generate students 
    Student s1 = Student("Sheldon", 1, 5); 
    students[totalStudents++] = &s1; 
    // add courses to s1 
    s1.addCourse(courses[0]); 
    s1.addCourse(courses[1]); 
    s1.addCourse(courses[2]); 
    s1.addCourse(courses[3]); 
    s1.addCourse(courses[4]); 
    s1.addCourse(courses[5]); 
    s1. setGradePoint (gradePoints, s1.getTotalCourses()); 
    s1.display(); 
    Student s2 = Student("Penny", 2, 5); 
    students[totalStudents++] = &s2; 
    s2.addCourse(courses[0]); 
    s2.addCourse(courses[2]); 
    s2.addCourse(courses[5]); 
    s2. setGradePoint (gradePoints, s2.getTotalCourses()); 
    s2. setGradePoint (courses[0], 3.25); 
    s2.display(); 
    Student s3 = s2; 
    students[totalStudents++] = &s3; 
    s3.setName("Leonard"); 
    s3.setId(3); 
    s3. setGradePoint (gradePoints, s3.getTotalCourses()); 
    s3.addCourse(courses[1], 3.75); 
    s3.display(); 
    Student s4 = s3; 
    students[totalStudents++] = &s4; 
    s4.setInfo("Howard", 4); 
    s4. setGradePoint (gradePoints, s4.getTotalCourses()); 
    s4.addCourse(courses[3], 3.75); 
    s4.display(); 
    Student s5 = s4; 
    students[totalStudents++] = &s5; 
    s5.setInfo("Raj", 5); 
    s5. setGradePoint (gradePoints, s5.getTotalCourses()); 
    s5. setGradePoint (courses[0], 1.5); 
    s5. setGradePoint (courses[2], 2.0); 
    s5. setGradePoint (courses[5], 1.75); 
    s5. setGradePoint (courses[3], 3.75); 
    s5.display(); 
    int failedCount; 
    Course* failedCourses = s5.getFailedCourses(failedCount); 
    cout << "Failed Courses for " << s5.getName() << ":" << endl; 
    for (int i = 0; i < failedCount; ++i) { 
    failedCourses[i].display(); 
    cout << endl; 
    } 
    delete[] failedCourses; 
    cout << "==================================" << endl; 
    Student topper = getTopper(); 
    cout << "Topper: " << topper.getName() << endl; 
    cout << "Topper CGPA: " << topper.getCGPA() << endl; 
    cout << "==================================" << endl; 
    for (int i = 0; i < COURSE_COUNT; ++i) { 
    Course c = courses[i]; 
    Student topperInCourse = getTopper(c); 
    cout << "Topper in " << c.getName() << ": " << 
    topperInCourse.getName() << endl; 
    cout << "Topper in " << c.getName() << " gradePoint: " << 
    topperInCourse. getGradePoint (c) << endl; 
    cout << "==================================" << endl; 
    } 
    return 0; 
    } 
    