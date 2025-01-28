import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        String input;
        int result;
        while(true) {
            input = scan.nextLine();
            if(Integer.parseInt(input) == 0) {
                scan.close();
                return;
            }
            result = 0;

            char[] nums = input.toCharArray();
            
            result += (2 + nums.length-1);
            //  1은 2cm, 2는 3cm, 0은 4cm를 차지한다.
            for(char num : nums) {
                if(num == '1') {
                    result += 2;
                }
                else if(num == '0') {
                    result += 4;
                }
                else {
                    result += 3;
                }
            }
            System.out.println(result);
        }
    }
}
