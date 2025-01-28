import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private int N;
    private int D;
    private int[][] des;
    private int[] distance;

    public static void main(String[] args) {
        Main m = new Main();
        m.input();
        m.solution();
    }

    private void input() {
        try(BufferedReader re = new BufferedReader(new InputStreamReader(System.in))) {
            String[] _input =  re.readLine().split(" ");
            this.N = Integer.parseInt(_input[0]);
            this.D = Integer.parseInt(_input[1]);

            this.des = new int[this.N][3];

            for(int i = 0; i < this.N; i++) {
                _input =  re.readLine().split(" ");
                if(this.D >= Integer.parseInt(_input[1]) && Integer.parseInt(_input[1]) > Integer.parseInt(_input[0])) {
                    des[i][0] = Integer.parseInt(_input[0]);
                    des[i][1] = Integer.parseInt(_input[1]);
                    des[i][2] = Integer.parseInt(_input[2]);
                }
            }
            this.distance = new int[this.D + 1];
            for(int i = 0; i < this.distance.length; i++) {

                this.distance[i] = i;
            }

        }catch(IOException e) {
            e.printStackTrace();
        }
    }

    private void solution() {
        
        for(int i = 0; i <= this.D; i++) {
            if(i > 0) {
                this.distance[i] = Math.min(this.distance[i], this.distance[i-1]+1);
            }
            for(int j = 0; j < this.des.length; j++) {
                if(this.des[j][0] == i && this.des[j][1] <= this.D) {
                    this.distance[this.des[j][1]] = Math.min(this.distance[this.des[j][1]], this.distance[this.des[j][0]] + this.des[j][2]);
                }
            }
        }
        System.out.println(this.distance[this.D]);
    }
}
