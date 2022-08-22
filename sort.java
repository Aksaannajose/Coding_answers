/*Given an array of integers and a target value, determine if there are any two integers in the array 
whose sum is equal to the given target value. Return true if the sum exists and return false if it does 
not.
Constraint:
1<=integers<=100
Input: No. of integers = 4, Numbers = [2, 7, 11, 15], Target Sum = 9,
Output:
Possible
*/
/*Test cases that used : JunitTestCase, TestJunitTestCase
*/

import java.util.HashMap;
import java.util.Map;
 
class Main
{
    // Function to find a pair in an array with a given sum using hashing
    public static void findPair(int[] nums, int target)
    {
       
        Map<Integer, Integer> map = new HashMap<>();
 
     
        for (int i = 0; i < nums.length; i++)
        {
         
            if (map.containsKey(target - nums[i]))
            {
                System.out.printf("Pair found (%d, %d)",
                    nums[map.get(target - nums[i])], nums[i]);
                return;
            }
 
            // store index of the current element in the map
            map.put(nums[i], i);
        }
 
        
        System.out.println("Pair not found");
    }
 
    public static void main (String[] args)
    {
        int[] nums = { 2, 7,11, 15 };
        int target = 9;
 
        findPair(nums, target);
    }
}

