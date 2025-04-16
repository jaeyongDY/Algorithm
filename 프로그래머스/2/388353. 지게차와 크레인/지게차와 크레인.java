import java.util.*;


class Solution {
    static int[] dx = {0, 0, 1, -1}; // 상하좌우 이동
    static int[] dy = {1, -1, 0, 0};
    static int N, M;

    public static int solution(String[] board, String[] requests) {
        N = board.length + 2;  // 테두리 때문에 +2
        M = board[0].length() + 2;

        // 1. 창고에 외곽 '0'을 추가
        char[][] map = new char[N][M];
        for (char[] row : map) Arrays.fill(row, '0');

        for (int i = 0; i < board.length; i++) {
            char[] line = board[i].toCharArray();
            for (int j = 0; j < line.length; j++) {
                map[i + 1][j + 1] = line[j];  // 테두리 고려해서 +1
            }
        }

        // 2. 요청 처리
        for (String req : requests) {
            if (req.length() == 1) {
                useFork(map, req.charAt(0));
            } else {
                useCrane(map, req.charAt(0));
            }
        }

        // 3. 남은 컨테이너 개수 세기
        int count = 0;
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (Character.isUpperCase(map[i][j])) count++;
            }
        }
        return count;
    }

    // 지게차: 외부랑 닿은 특정 알파벳만 제거
    static void useFork(char[][] map, char target) {
        boolean[][] outside = new boolean[N][M];
        markOutside(map, outside); // 외부 빈칸 표시

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (map[i][j] == target) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (outside[ni][nj]) {
                            map[i][j] = '0';  // 제거
                            break;
                        }
                    }
                }
            }
        }
    }

    // 크레인: 해당 알파벳 모두 제거
    static void useCrane(char[][] map, char target) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (map[i][j] == target) {
                    map[i][j] = '0';
                }
            }
        }
    }

    // 외부 빈칸 표시
    static void markOutside(char[][] map, boolean[][] outside) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        outside[0][0] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int d = 0; d < 4; d++) {
                int nx = cur[0] + dx[d], ny = cur[1] + dy[d];
                if (0 <= nx && nx < N && 0 <= ny && ny < M && !outside[nx][ny] && map[nx][ny] == '0') {
                    outside[nx][ny] = true;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }
}