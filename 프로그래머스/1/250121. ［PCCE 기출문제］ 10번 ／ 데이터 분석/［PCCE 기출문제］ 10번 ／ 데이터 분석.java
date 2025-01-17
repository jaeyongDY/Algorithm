import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        int[][] answer = {};
                Map<String, Integer> map = new HashMap<>();
        map.put("code", 0);
        map.put("date", 1);
        map.put("maximum", 2);
        map.put("remain", 3);
        List<int[]> _data = Arrays.asList(data);

                answer =_data.stream().filter(item -> item[map.get(ext)] < val_ext ).sorted((a,b) -> a[map.get(sort_by)] - b[map.get(sort_by)]).toArray(int[][]::new);

        return answer;
    }
}