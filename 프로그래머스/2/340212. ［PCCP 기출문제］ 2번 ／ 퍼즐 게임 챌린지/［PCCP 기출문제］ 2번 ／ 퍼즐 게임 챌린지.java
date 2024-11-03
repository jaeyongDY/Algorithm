import java.util.Arrays;
class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
 
        int size = diffs.length;
        int start = 0;
        int end = Arrays.stream(diffs).max().getAsInt();
        int mid;
        int temp = end;
        while(start + 1 < end) {
        	// 이분탐색
        	long check = 0;
        	mid =  (start + end) / 2;
        	for(int i = 0; i < size; i++) {        		
            	check += getNum(diffs[i], times[i], mid, i == 0 ? 0 : times[i-1]);
            	if(limit < check) {
            		start = mid;
            		break;
            	}
            }
        	// 여기서 기존 값과 check값을 비교하여 answer 값 비교
        	if(temp > mid && limit >= check) {
        		temp = mid;
        		end = mid;
        	}
        }
        answer = temp;
        
        return answer;
    }
	
	private long getNum(int diff, int time, int level, int prevtime) {
		long retresult = 0;
		
		if(level >= diff) {		
			retresult = time;
			return retresult;
		}
		retresult = (diff-level) * (prevtime + time) + time;
		
		return retresult;
	}
	
	
}