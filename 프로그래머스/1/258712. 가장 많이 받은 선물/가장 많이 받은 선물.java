import java.util.HashMap;
import java.util.Map;
import java.util.Map.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        int friendLen = friends.length;

        int[][] giftMap = new int[friendLen][friendLen];

        for(int i = 0; i < gifts.length; i++) {
        	String[] giftName = gifts[i].split(" ");
        	String giveName = giftName[0];
        	int giveIndex = findFriend(friends, giveName);
        	String reciveName = giftName[1];
        	int reciveIndex = findFriend(friends, reciveName);
        	giftMap[giveIndex][reciveIndex] += 1;
        }
        Map<Integer, Integer> giftEx = new HashMap<>();
        for(int i = 0; i < friendLen; i++) {
        	int giveCnt = 0;
        	int reciveCnt = 0;
        	for(int j = 0; j < friendLen; j++) {
        		if(i == j) continue;
        		giveCnt += giftMap[i][j];
        		reciveCnt += giftMap[j][i];
        	}
        	giftEx.put(i, giveCnt - reciveCnt);
        }
        Map<Integer, Integer> giftAnswer = new HashMap<>();

        for(int i = 0; i < giftMap.length; i++) {
        	for(int j = 0 ; j < giftMap[i].length; j++) {
        		if( i == j) continue;
        		if((giftMap[i][j] != 0 || giftMap[j][i] != 0) && giftMap[i][j] > giftMap[j][i]) {
        			giftAnswer.put(i, giftAnswer.getOrDefault(i, 0) + 1);
        		}
        		else if((giftMap[i][j] == 0 && giftMap[j][i]== 0) || (giftMap[i][j] == giftMap[j][i])) {
        			if(giftEx.get(i) == giftEx.get(j)) {
        				continue;
        			}
        			if(giftEx.get(i) > giftEx.get(j)) {
        				giftAnswer.put(i, giftAnswer.getOrDefault(i, 0) + 1);
        			}
        		}
        	}
        }

        for(Entry<Integer, Integer> data:  giftAnswer.entrySet()) {
        	answer = Math.max(data.getValue(), answer);
        }

        return answer;
    }
    private int findFriend(String[] friends, String name) {
		for(int i = 0; i < friends.length; i++) {
			if(friends[i].equals(name)) {
				return i;
			}
		}
		return -1;
	}
}

