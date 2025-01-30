import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    private static Map<Character, Integer> charMap;
    private static int result = 0;
    public static void main(String[] args) {
        String S;
        
        Scanner scan = new Scanner(System.in);

        S = scan.nextLine();

        scan.close();

        charMap = new HashMap<>();
        
        for(char data : S.toCharArray()) {
            charMap.put(data, charMap.getOrDefault(data, 0) + 1);
        }

        backTracking("", ' ', S.length());

        System.out.println(result);
    }

    private static void backTracking(String inData, char prevChar, int dataLen) {
        if(dataLen == inData.length()) {
            result++;
            return;
        }

        for(char c : charMap.keySet()) {
            if(charMap.get(c) > 0 && c != prevChar) {
                charMap.put(c, charMap.get(c)-1);
                backTracking(inData + c, c, dataLen);
                charMap.put(c, charMap.get(c)+1);
            }
        }
    }

}