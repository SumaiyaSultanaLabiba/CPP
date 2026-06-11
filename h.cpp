 #include <iostream>
 #include <list>
 using namespace std; 
int main(){
   list<int> lst1, lst2;
   list<int>::iterator p = lst1.begin();
   for(int i = 0; i < 5; i++){
      lst1.push_back(2*i);//0 2 4 6 8
      lst2.push_front(2*i+1); //9 7 5 3 1
   }
   cout<<"Labu:"<<*p<<endl;
   lst2.splice(p,lst1);
   p = lst2.begin();
   while(p != lst2.end()){
      cout << *p << " ";
      p++;
   }   cout << endl;
   cout << "Size1: " << lst1.size() << " ";
   cout << "Size2: " << lst2.size() << endl;
   lst1.reverse();
    p = lst1.begin();
   while(p != lst1.end()){
      cout << *p << " ";
      p++;
   }
   cout << endl; 
   for(int i = 0; i < 3; i++){
      lst2.push_back(i+20);
   }
   lst1.splice(lst1.begin(), lst2);
   //lst1.merge(lst2);
   cout << "Size1: " << lst1.size() << " ";
   cout << "Size2: " << lst2.size() << endl;
   p = lst1.begin(); 
   while(p != lst1.end()){
      cout << *p << " ";
      p++;
   }
   cout << endl;
    lst1.sort();
   p = lst1.begin();
   while(p != lst1.end()){
      cout << *p << " ";
      p++;
   }
   cout << endl;
   return 0;
 }