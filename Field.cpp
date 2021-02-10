#include <vector>
#include <stdexcept>
#include <iostream>
#include "Field.h"



//does the precompuation for weights and pathcost
void Field::precomputation()
{
  pathcost.resize(arr.size());//creating the rows of the pathcost array
  weights.resize(arr.size()); //creating the rows of the weight array
  for(int i=0; i<arr.size(); i++)
    //iterates through each row
  {
    weights[i].resize(arr[i].size(), 0); // creating the columns of the row i of the weights array
    pathcost[i].resize(arr[i].size(),0);//creating the columns of the row i of the pathcost array
    for(int j=0; j<arr[i].size(); j++) //iterates through each col
    {
      int num1=0; // weight of prev col in same row
      int num2=0; // weight of prev row in same col
      int num3=0; // weight of prev row and prev col
      int num4=0; // value of current cell
      
      if(j>0) 
      {
        // if we are not at the first column
        num1=weights[i][j-1]; //get the value at the previous col
      }
      if(i>0)
      {
        // if we are not in the first row
        num2 = weights[i-1][j]; //ge the value at the previous row
      }
      if(i>0 && j>0) //if we are not the in the first row and we are not in the first col
      {
        num3 = weights[i-1][j-1]; //get the value at the prev row and prev col
      }
      num4 = arr[i][j]; //get the value at the current value of the cell
      
      weights[i][j]=num1+num2-num3+num4; //returns the sum of that particular cell
      
      int prev_value=0;
      
      if(j>0 && i>0) //if we are not in first col and first row
      {
        if(pathcost[i-1][j] < pathcost[i][j-1]) //if prev row of the same col< prev col of the same row
        {
          prev_value = pathcost[i-1][j];//get the value at the prev row of the same col
        }
        else
        {
          prev_value = pathcost[i][j-1]; //else, get the value at the prev col of the same row
        }
      }
      else if(j>0) // i==0, j>0
      {
        prev_value = pathcost[i][j-1];//get the value at the prev col of the same row
      }
      else if(i>0)// j==0, i>0
      {
        prev_value = pathcost[i-1][j];//get the value at the prev row of the same col
      }
      
      pathcost[i][j]=prev_value + arr[i][j]; //returns the cheapest cost of that particular element
      
    }
}
}   

//copies the content of the obj to an arr and calls the precomputation function
Field::Field(const std::vector<std::vector<int>> & obj)
{
    arr = obj;//copies everthing from obj to the array
    precomputation(); //call the precomutation function
  
}

//move the content of the obj to an arr and calls the precomputation function
Field::Field(std::vector<std::vector<int>> && rhs)
{
   arr = std::move(rhs); //we move the content of rhs to arr
   precomputation(); //call the precomputation function
}

//Function returns the sum of all numbers in the define rectangle
int Field::Weight(int x1, int y1, int x2, int y2 ) 
{
   int numrows=arr.size(); //numrows gets the number of arr's row
   int numcols=0; 
   if(numrows>0) //only if the vector of vector which has been passed is not empty
   {
     numcols=arr[0].size(); //get the number of cols
   }
   if(x1<0 || x2<0 || y1<0 || y2<0|| x1>=numcols|| x2>=numcols || y1>=numrows||y2>=numrows)
   {
     throw std::out_of_range("Out of range"); //throws out of range exception if goes coordinates beyond the array boundaries or if the vector is empty
   }
  
  // (1,2) (2,1) --> (1,1), (2, 2)-->Weight(1,1,2,2) 
  //making x1, y1-> top-left and x2 and y2->bottom right
   
   if(x1>x2)
    {
      int tmp=x1;
      x1=x2;
      x2=tmp;
    }
    if(y1>y2)
    {
      int tmp=y1;
      y1=y2;
      y2=tmp;
    }
  
    int w=weights[y2][x2]; // weight at bottom-right cell--->18
  
    int w1=0;
    if(x1>0)
    {
      w1=weights[y2][x1-1];//get the value of prev row of the same col--->3
    }
  
    int w2=0;
    if(y1 > 0)
    {
      w2=weights[y1-1][x2];//get the value of the prev col of the same row--->6
    }

    int w3=0;
    if(y1 > 0 && x1>0)
    {
      w3=weights[y1-1][x1-1];//get the value of prev col and prev row---->1
    }
    
    return (w-w1-w2+w3);//---->Weigh(1,1,2,2)=18-3-6+1
}

//This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner
int Field::PathCost() 
{
    //if the vector is empty then return 0
     if(arr.size()==0 || arr[0].size()==0)
     {
       return 0;
     }
  return pathcost[arr.size()-1][arr[0].size()-1];//returns the element in the last row and last col
}
//for testing purpose
//printing all the elements in the arr, weight and pathcost (vector of vectors) by iteration through their rows and col.
//used for testing purposes.
void Field::print()
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[0].size(); j++)
        {
            std::cout<<arr[i][j]<<" ";
        }

        std::cout<<std::endl;
    }

    std::cout<<std::endl;
     
    for(int i=0; i<weights.size(); i++)
    {
        for(int j=0; j<weights[0].size(); j++)
        {
            std::cout<<weights[i][j]<<" ";
        }

        std::cout<<std::endl;
    }
   
   std::cout<<std::endl;

   for(int i=0; i<pathcost.size(); i++)
    {
        for(int j=0; j<pathcost[0].size(); j++)
        {
            std::cout<<pathcost[i][j]<<" ";
        }

        std::cout<<std::endl;
    }

}