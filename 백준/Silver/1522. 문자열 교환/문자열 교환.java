import java.util.Scanner;

public class Main {
    private static int result = Integer.MAX_VALUE;
    private static String input;
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        input = scan.nextLine();

        scan.close();
        int a = 0;

        for(int i = 0; i < input.length(); i++) {
            if(input.charAt(i) == 'a') {
                a += 1;
            }
        }
        if(a == input.length() || a == 0) {
            result = 0;
        }
        else {
            window(input + input , a);
        }
        System.out.println(result);
    }

    private static void window(String data, int aLen) {
        int bCnt = includeB(data.substring(0, aLen));
        result = Math.min(bCnt, result);
        for(int i = 1 ; i < input.length(); i++) {
            if(data.charAt(i-1) == 'b') {
                bCnt--;
            }
            if(data.charAt(aLen + i - 1) == 'b') {
                bCnt++;
            }

            result = Math.min(result, bCnt);
        }
    }

    private static int includeB(String data) {
        int b = 0;
        for(char c : data.toCharArray()){
            if(c == 'b') {
                b++;
            }
        }
        return b;
    }

}
