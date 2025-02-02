
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {


		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int S = scan.nextInt();
		int M = scan.nextInt();

		boolean[][] song = new boolean[N+1][M+1];
		int[] V = new int[N];

		for(int i = 0; i < N; i++) {
			V[i] = scan.nextInt();
		}

		song[0][S] = true;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M+1; j++) {
				if(song[i][j]) {
					if(j + V[i] <= M) {
						song[i+1][j + V[i]] = true;
					}

					if(j - V[i] >= 0) {
						song[i+1][j - V[i]] = true;
					}
				}
			}
		}

		int result = -1;
		for(int i = M; i >= 0; i--) {
			if(song[N][i]) {
				result = Math.max(result, i);
			}
		}

		System.out.println(result);

		scan.close();
	}

}
