
import java.util.Scanner;

public class Main {

    int R, C, K;
    char map[][];
    boolean visited[][];
    int[] moveX = {1, 0, -1, 0};
    int[] moveY = {0, 1, 0, -1};
    int result = 0;

    public static void main(String[] args) {
        Main m = new Main();
        m.input();
        m.solution();
    }

    public void input() {
        Scanner scan = new Scanner(System.in);

        this.R = scan.nextInt();
        this.C = scan.nextInt();
        this.K = scan.nextInt();
        scan.nextLine(); // 개행 문자 소비

        map = new char[this.R][this.C];
        
        for(int i = 0; i < R; i++) {
            String line = scan.nextLine();
            map[i] = line.toCharArray();
        }
        visited = new boolean[this.R][this.C];
        visited[this.R-1][0] = true;
        scan.close();
    }

    public int solution() {
        // 시작 -> (r-1, 0);
        // 도착 -> (0, c-1);

        dfs(this.R - 1, 0, 1);
        System.out.println(this.result);
        return 0;
    }


    public void dfs(int r, int c, int n) {

         for(int i = 0; i < 4; i++) {

            if(r == 0 && c == this.C - 1) {
                if(n == this.K) this.result++;
                break;
            }
            int x = moveX[i] + r;
            int y = moveY[i] + c;
            
            if(x >= this.R || x < 0 || y >= this.C || y < 0) {
                continue;
            }
        
            if(visited[x][y] || map[x][y] == 'T') continue;
            
            visited[x][y] = true;
            dfs(x, y, n + 1);
            visited[x][y] = false;
        }
        
    }

}
