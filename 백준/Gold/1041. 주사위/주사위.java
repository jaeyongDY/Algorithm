import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        double result = 0;
        long N;
        int[] dice = new int[6];

        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        for(int i = 0; i < 6; i++) {
            dice[i] = scan.nextInt();
        }
        scan.close();

        int[][] oppsite = {{0,5}, {1,4}, {2,3}, {3,2}, {4,1}, {5,0}};

        // N이 1일때
        // 2면의 최소값
        // 3면의 최소값

        int oneMin = Integer.MAX_VALUE;
        int twoMin = Integer.MAX_VALUE;
        int threeMin = Integer.MAX_VALUE;
        
        for(int i = 0; i < 6; i++) {
            oneMin = Math.min(dice[i], oneMin);
        }

        for(int i = 0; i < 6; i++) {
            for(int j = i+1; j < 6; j++) {
                if(j != oppsite[i][1]) {
                    twoMin = Math.min(dice[i] + dice[j], twoMin);
                }
            }
        }

        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 6; k++) {
                    if(i != j &&  j != k && k != i) {
                        if(j != oppsite[i][1] && k != oppsite[j][1] && k != oppsite[i][1]) {
                            threeMin = Math.min(dice[i] + dice[j] + dice[k], threeMin);
                        }
                    }
                }
            }
        }

        if(N == 1) {
            int maxNum = 0;
            int sumNum = 0;
            for(int i = 0; i < 6; i++) {
                maxNum = Math.max(dice[i], maxNum);
                sumNum += dice[i];
            }
            sumNum -= maxNum;
            result = sumNum;
        }
        else {
            // 1면  
            double oneValue = (5 * N*N - 16 * N + 12) * oneMin;
            // 2면
            double twoValue = ((N-2)*4 + (N-1)*4) * twoMin;
            // 3면
            double threeValue = 4 * threeMin;
            result = oneValue + twoValue + threeValue;
        }

        System.out.println((long)result);
    }
}