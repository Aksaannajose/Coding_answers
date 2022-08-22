/*You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash 
them together. Suppose the heaviest two stones have weights x and y with x <= y.
The result of this smash is:
●If x == y, both stones are destroyed, and
●If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y -
x.
At the end of the game, there is at most one stone left.
Return the smallest possible weight of the left stone. If there are no stones left, return 0.
*/

import java.util.Maxheap;
import java.util.Map;

       public class lastStoneWeight {
           public static void lastStoneWeight(int[] vector, int max_heap);
               int lastStoneWeight(vector<int>& stones) {

        priority_queue <int> max_heap;
        int n = stones.size();
        
        for(int i=0;i<n;++i)
            max_heap.push(stones[i]);
        
        int first,second;
        while(n > 1)
        {
            first = max_heap.top();
            max_heap.pop();
            second = max_heap.top();
            max_heap.pop();
            n -= 2;
            
            if(first-second > 0)
            {
                max_heap.push(first-second);
                n+=1;
            }
        }
        
        if(!max_heap.empty())
            return max_heap.top();
        return 0;
    }
};

