import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution {
    int answer = 0;
    public int solution(int n, int[][] q, int[] ans) {
        combine(n, q, ans, 1, new ArrayList<>());
        return answer;
    }

    private void combine(int n, int[][] q, int[] ans, int start, List<Integer> nums) {

        if(nums.size() == 5) {
            // chk 검증로직
            chk(q, ans, nums);
        }

        for(int i = start; i <= n; i++) {
            nums.add(i);
            combine(n, q, ans, i + 1, nums);
            nums.remove(nums.size()-1);
        }
    }


    private void chk(int[][] q, int[] ans, List<Integer> nums) {
        Set<Integer> chkSet = new HashSet<>(nums);
        for(int i = 0; i < q.length; i++) {
            int count = 0;
            for(int j = 0; j < q[i].length; j++){
                if(chkSet.contains(q[i][j])) {
                    count++;
                }
            }
            if(count != ans[i]) {
                return;
            }
        }
        answer++;
    }
}
