import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private int N;
    private final int MOD = 9901;

    public static void main(String[] args) {
        Main m = new Main();

        m.input();
        m.solution();
    }

    private void input() {

        try(BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in))) {
            N = Integer.parseInt(buffer.readLine());
        } catch(IOException e) {
            e.printStackTrace();
        }

    }

    private void solution() {

        int[][] map = new int[this.N + 1][3];

        map[1][0] = 1;
        map[1][1] = 1;
        map[1][2] = 1;

        for(int i = 2; i <= this.N; i++) {
            map[i][0] = (map[i-1][0] + map[i-1][1] + map[i-1][2]) % this.MOD;
            map[i][1] = (map[i-1][0] + map[i-1][2]) % this.MOD;
            map[i][2] = (map[i-1][0] + map[i-1][1]) % this.MOD;
        }

        System.out.println((map[this.N][0] + map[this.N][1] + map[this.N][2]) % this.MOD);

    }
}