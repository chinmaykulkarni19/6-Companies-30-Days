class Solution {
public:
    int myjos(int n, int k)
    {
        //if n is itself 1 then no matter how many k we took it will always come to that person so return 0.
        if(n==1)
        {
            return 0;
        }
        //1)WHY n-1??
        //Because we want to decrease the number of persons as mentioned in the question.At one time we are decreasing one person at a time so n-1

        //2)WHY +k??
        //I am attaching a page,while explaining look into that page.
        //Lets think like what would have happened if we have not inluded +k? 
        //eg-: n=5 k=3 -->(let us consider n is from 0)-->0,1,2,3,4-->(delete 2)-->0,1,3,4-->now it should start from 3 as mentioned in question but what happens is it will again start from 0-->0,1,4 it is deleting 3 but in reality it should delete 1        
        else{
            return (myjos(n-1,k)+k)%n;
        }
    }
    int findTheWinner(int n, int k) {
        //myjos function is from 0 to n-1 i.e n is starting from 0 to n-1 so to start from 1 just add 1 to the function.
        return myjos(n,k)+1;
    }
};