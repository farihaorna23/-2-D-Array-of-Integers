#include <string>
#include <iostream>
#include "Field.h"

using namespace std;

int main()
{
	//g++ -std=c++11 main.cpp -o pi
	//g++ -std=c++11  *.cpp  -o pi
    //g++ -std=c++11 main.cpp Field.cpp -o pi
    //g++ -std=c++11 -fsanitize=address,undefined -g main.cpp Field.cpp -o pi
    //Fariha.Hossain74
    //rg7w7eYE
    

    vector<vector<int>> ve = {   {1,2,3,4,5,6},
                                 {1,2,3,4,5,6},
                                 {1,2,3,4,5,6},
                                 {1,2,3,4,5,6},
                                 {1,2,3,4,5,6},
                            };
    vector<vector<int>> s = {   {1,2,3},
                                {4,5,6},
                                {1,2,3},
                            };
    vector<vector<int>> sa = {  {1,2,4},
                                {1,2,4},
                                {1,2,4},
    };
    vector<vector<int>> si = {  {8, 9, 0, 0},
                                {4, 8, 0, 0},
                                {3, 4, 8, 7}
                            };
    vector<vector<int>> e;
    
    Field obj(ve);
    cout << "Path: "<< obj.PathCost()<<endl;    //25
    cout << obj.Weight(0,0,0,0)<<endl;          //1
    cout << obj.Weight(0,1,0,0)<<endl;          //2
    cout << obj.Weight(1,0,0,0)<<endl;          //3
    cout << obj.Weight(0,0,1,0)<<endl;          //3
    cout << obj.Weight(0,0,0,1)<<endl;          //2

    cout << obj.Weight(1,2,4,0)<<endl;          //42
    cout << obj.Weight(4,0, 1,2)<<endl;          //42
    cout << obj.Weight(1,1,2,2)<<endl;          //10
    cout << obj.Weight(2,2,1,1)<<endl;          //10
    //cout << obj.Weight(1,9,2,0)<<endl;   
    cout << obj.Weight(0,1,4,4)<<endl;          //60
    cout << obj.Weight(0,1,5,4)<<endl;          //84
    cout << obj.Weight(1,4,5,4)<<endl;          //20
    cout << obj.Weight(0,0,5,4)<<endl;          //105

    cout << endl;
    Field obj2(s);
    cout << "Path: "<< obj2.PathCost()<<endl;   //11
    cout << obj2.Weight(0,0,0,0)<<endl;          //1
    cout << obj2.Weight(0,1,0,0)<<endl;          //5
    cout << obj2.Weight(1,0,0,0)<<endl;          //3
    cout << obj2.Weight(0,0,1,0)<<endl;          //3
    cout << obj2.Weight(0,0,0,1)<<endl;          //5
    cout << obj2.Weight(2,2,0,1)<<endl;          //21

    cout << endl;
    Field oj(si);
    cout << "Path: "<< oj.PathCost()<<endl;    //24
    cout << oj.Weight(0,0,0,0)<<endl;          //8
    cout << oj.Weight(0,1,0,0)<<endl;          //12
    cout << oj.Weight(1,0,0,0)<<endl;          //17
    cout << oj.Weight(0,0,1,0)<<endl;          //17
    cout << oj.Weight(0,0,0,1)<<endl;          //12
    cout << oj.Weight(2,2,0,1)<<endl;          //27

    cout << endl;
    Field ss({{1,2,3},
             {1,2,3}}); 
    cout << "Path: "<<ss.PathCost()<<endl;     //7
    cout << ss.Weight(0,0,0,0)<<endl;          //1
    cout << ss.Weight(0,1,0,0)<<endl;          //2
    cout << ss.Weight(1,0,0,0)<<endl;          //3
    cout << ss.Weight(0,0,1,0)<<endl;          //3
    cout << ss.Weight(0,0,0,1)<<endl;          //2
    cout << oj.Weight(2,2,0,1)<<endl;          //27
    
    
    
    /*
    
    vector<vector<int>> sa = {  {1,2,4},
                                {1,2,4},
                                {1,2,4},
    };

    Field aaaa(sa);
    cout << "Path: "<<aaaa.PathCost()<<endl;     //9
    cout << aaaa.Weight(0,0,0,0)<<endl;          //1
    cout << aaaa.Weight(0,1,0,0)<<endl;          //2
    cout << aaaa.Weight(1,0,0,0)<<endl;          //3
    cout << aaaa.Weight(0,0,1,0)<<endl;          //3
    cout << aaaa.Weight(0,0,0,1)<<endl;          //2
    cout << aaaa.Weight(2,2,0,1)<<endl;          //14
   */

    /*
    
    
    
    vector<vector<int>> ve = {{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},};
    vector<vector<int>> s = { {1,2,3},{4,5,6},{1,2,3}};
    vector<vector<int>> vec={};//empty vector


    cout<<"Obj 1"<<endl;

    Field obj(ve);
    obj.print();
    cout << obj.Weight(1,1,1,1)<<endl;//2
    cout << obj.Weight(1,2,4,0)<<endl;//42
    cout<<obj.Weight(2,1,0,0)<<endl;//12
    cout<<obj.Weight(0,0,0,4)<<endl;//5
    cout<<obj.Weight(1,1,0,4)<<endl;//12
    cout << obj.Weight(0,1,2,4)<<endl;//24
    //cout<<obj.Weight(-1,1,1,1)<<endl; //throw an exception 1
    //cout<<obj.Weight(1,-1,1,1)<<endl; //throw an exception 2
    //cout<<obj.Weight(1,1,-1,1)<<endl; //throw an exception 3
    //cout<<obj.Weight(1,1,1,-1)<<endl; //throw an exception 4
    //cout<<obj.Weight(100,1,1,1)<<endl; //throw an exception 5
    //cout<<obj.Weight(1,100,1,1)<<endl; //throw an exception 6
    //cout<<obj.Weight(1,1,100,1)<<endl; //throw an exception 7
    cout<<obj.Weight(1,1,1,100)<<endl; //throw an exception 8
    //cout<<obj.Weight(8,9,2,1)<<endl; //throw an exception 
    cout << obj.Weight(2,2,1,1)<<endl;//10
    cout << obj.Weight(1,2,2,1)<<endl;//10
    
    cout << obj.PathCost()<<endl;//25
    cout << endl;
    cout << endl;

    cout<<"Obj 2"<<endl;

    Field obj2(s);
    obj2.print();
    cout << obj2.Weight(1,1,2,2)<<endl; //16
    cout << obj2.PathCost()<<endl;//11
    //cout << obj.Weight(1,2,4,0)<<endl;
  
    cout<<"Obj 3"<<endl;

    Field obj3(vec);
    cout<<obj3.PathCost()<<endl;//0
    cout << obj3.Weight(1,2,4,0)<<endl;//throw an exception

   */
    return 0;
}