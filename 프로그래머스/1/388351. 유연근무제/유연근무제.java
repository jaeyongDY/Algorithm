class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;

        for(int i = 0; i < timelogs.length; i++) {
            int varStart = startday;
            int count = 0;
            for(int j = 0; j < timelogs[i].length; j++) {
                varStart = j == 0 ? varStart : varStart + 1 > 7 ? 1 : varStart + 1;
                if(varStart == 6 || varStart == 7) {
                    continue;
                }
                int schedule = schedules[i];
                int calMin = (schedule / 100) * 60 + schedule % 100 + 10;
                int maxSchedule = (calMin / 60 * 100) + calMin % 60;

                if(timelogs[i][j] <= maxSchedule) {
                    count++;
                }
            }
            if(count == 5) {
                answer++;
            }
        }
        return answer;
    }
}