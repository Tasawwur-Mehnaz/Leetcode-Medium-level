You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)


Solution:

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0,j=n-1,ans=0,sum=people[0];
        if(n==1)
            return 1;
//         if(n==2)
//         {
//             if((sum+people[1])<=limit)            This can be included.
//                 return 1;
//             else 
//                 return 2;
//         }
        while(i<=j)
        {
          
            int sum=people[i]+people[j];
            if(sum<=limit)
            { 
             
              i++;
              j--;
              ans++;
            }
            else
            {
                j--;
                ans++;
            }
          
        }
        return ans;
    }
};
