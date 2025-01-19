import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
class Solution {
    public static int solution(int[][] points, int[][] routes) {
        int answer = 0;

        // 모든 로봇에 대서 1초 이동 좌표 및  저장
        // 로봇 순서 
        Map<Integer, Map<String, Integer>>  pos = new HashMap<>();
        
        
        for(int i = 0; i < routes.length; i++) {
            int index = 1;

            int startx = points[routes[i][0]-1][0];
            int starty = points[routes[i][0]-1][1];
            if(!pos.containsKey(index)) {
                pos.put(index, new HashMap<String ,Integer>());
            }
            if(!pos.get(index).containsKey(startx+","+starty)) {
                pos.get(index).put(startx+","+starty, 1);    
            }
            else {
                pos.get(index).put(startx+","+starty, pos.get(index).get(startx+","+starty) + 1);
            }
            
            for(int j = 1; j < routes[i].length; j++) {
                // 좌표 1초 이동 로직
                int endx = points[routes[i][j]-1][0];
                int endy = points[routes[i][j]-1][1];

                while(true) {
                    index++;
                    if(endx != startx) {
                        if(endx > startx) {
                            startx++;
                        }
                        else {
                            startx--;
                        }
                    }
                    else if(endy != starty) {
                        // y축
                        if(endy > starty) {
                            starty++;
                        }
                        else {
                            starty--;
                        }
                    }
                    if(!pos.containsKey(index)) {
                        pos.put(index, new HashMap<String ,Integer>());
                    }
                    if(!pos.get(index).containsKey(startx+","+starty)) {
                        pos.get(index).put(startx+","+starty, 1);    
                    }
                    else {
                        pos.get(index).put(startx+","+starty, pos.get(index).get(startx+","+starty) + 1);
                    }
                    // System.out.println(index + "   " + startx+"," + starty + "   " + pos.get(index).get(startx+","+starty));
                    
                    if(endx == startx && endy == starty) {
                        break;
                    }
                }
            }
        }

        for(Entry<Integer, Map<String, Integer>> value : pos.entrySet()) {

            for(Entry<String, Integer> val :value.getValue().entrySet()) {
                if(val.getValue() >=2) {
                    answer += 1;
                }
            }
        }

        return answer;
    }
}