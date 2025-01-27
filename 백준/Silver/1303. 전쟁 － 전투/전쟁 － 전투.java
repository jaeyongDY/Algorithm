import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private Scanner scan;
    private Queue<int[]> que;
    private boolean visited[][];
    private char[][] map;
    private int n, m;
    private int[] moveX = {1, -1, 0, 0};
    private int[] moveY = {0, 0, 1, -1};
    private int white = 0, blue = 0;

    
    public static void main(String[] args) {
        Main m = new Main();
        
        m.input();
        m.solution();
    }

    private void input() {
        scan = new Scanner(System.in);

        this.n = scan.nextInt();
        this.m = scan.nextInt();
        scan.nextLine();
        map = new char[this.m][this.n];
        visited = new boolean[this.m][this.n];
        for(int i = 0; i < this.m; i++){
            map[i] = scan.nextLine().toCharArray();
        }
        scan.close();
    }

    private void solution() {

        // bfs start 0,0
        que = new LinkedList<>();

        for(int i = 0; i < this.m; i++) {
            for(int j = 0; j < this.n; j++) {
                if(!visited[i][j]) {
                    char shape = this.map[i][j];
                    int territory = bfs(i, j);
                    if(shape == 'W') {
                        this.white += Math.pow(territory, 2);
                    }
                    else {
                        this.blue += Math.pow(territory, 2);
                    }
                }
            }
        }
        System.out.println(this.white + " " + this.blue);
    }

    private int bfs(int x, int y) {
        this.que.add(new int[]{x, y});
        this.visited[x][y] = true;

        int cnt = 1;
        while(!this.que.isEmpty()) {
            int[] coordinate = this.que.poll();
            for(int i = 0; i < 4; i++) {
                int _x = coordinate[0] + moveX[i];
                int _y = coordinate[1] + moveY[i];
                if(_x < 0 || _x >= this.m || _y < 0 || _y >= this.n) {
                    continue;
                }
                if(this.map[_x][_y] == this.map[coordinate[0]][coordinate[1]] && !visited[_x][_y]) {
                    cnt++;
                    visited[_x][_y] = true;
                    this.que.add(new int[]{_x, _y});
                }
            }
        }
        return cnt;
    }
}