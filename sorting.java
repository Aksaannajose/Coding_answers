/*Input:
No. of integers = 5
Numbers = [2,4,5,7,8]

Target Sum = 11,

Output:
Possible
*/

import java.util.HashMap;
import java.util.Map;
 
class Main
{
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
            map.put(nums[i], i);
        }
        System.out.println("Pair not found");
    }
 
    public static void main (String[] args)
    {
        int[] nums = { 2, 4, 5, 7,8 };
        int target =11;
 
        findPair(nums, target);
    }
}

