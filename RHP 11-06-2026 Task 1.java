import java.util.Scanner;

class Solution {
    public int findMaxLength(int[] nums) {
        int res = 0, preSum = 0, n = nums.length;

        int[] map = new int[2 * n + 1];

        for (int i = 0; i < n; i++) {
            preSum += (nums[i] == 1) ? 1 : -1;

            if (preSum == 0) {
                res = i + 1;
            } else {
                int mapIndex = preSum + n;

                if (map[mapIndex] != 0) {
                    res = Math.max(res, i - (map[mapIndex] - 1));
                } else {
                    map[mapIndex] = i + 1;
                }
            }
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();   
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        Solution sol = new Solution();
        System.out.println(sol.findMaxLength(nums));

        sc.close();
    }
}