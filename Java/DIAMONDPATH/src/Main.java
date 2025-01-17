import java.io.IOException;
import java.util.Scanner;

public class Main {
	static int[][] diamond = new int[200][100];
	
	static void init_diamond(int height, int width) {
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++)
				diamond[j][i] = 0;
	}
	
	static void print_diamond(int height, int width) {
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				System.out.print(diamond[j][i] + " ");
			}
			System.out.print("\n");
		}
			
	}
	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int C, N = 0;
		C = scan.nextInt();

		for (int i = 1; i <= C; i++) {
			int l = 0;
			if (scan.hasNextInt()) {
				N = scan.nextInt();
				init_diamond(2*N, N);

				for (int j = 1; j <= N; j++) {
					for (int k = 0; k < j; k++) {
						if (l == 0)
							diamond[l][k] = scan.nextInt();
						else {
							if (k-1 > -1)
								diamond[l][k] = scan.nextInt() + Math.max(diamond[l-1][k], diamond[l-1][k-1]);
							else
								diamond[l][k] = scan.nextInt() + diamond[l-1][k];
						}
					}
					l++;
				}
				for (int j = N-1 ; j > 0; j--) {
					for (int k = 0; k < j; k++) {
						if (k+1 < 100)
							diamond[l][k] = scan.nextInt() + Math.max(diamond[l-1][k], diamond[l-1][k+1]);
						else
							diamond[l][k] = scan.nextInt() + diamond[l-1][k];
					}
					l++;
				}
			}
			// print_diamond(2*N, N);
			System.out.println(diamond[2*N-2][0]);
		}
		scan.close();
	}
}
