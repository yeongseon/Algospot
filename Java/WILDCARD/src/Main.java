import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private static boolean isMatch;
	
	public static void match(String wildcard, int widx, String fname, int fidx) {
		if (fidx == fname.length() - 1) {
			// 종료조건			
			if (widx == wildcard.length() - 1) {
				isMatch = true;
				return;
			} else {
				if (widx + 1 == wildcard.length() - 1) {
					if (wildcard.charAt(widx) == fname.charAt(fidx)) {
						//System.out.println(widx);
						if (wildcard.charAt(widx+1) == '*')
							isMatch = true;
					}
				}
				
				if (!isMatch)
					isMatch = false;
				return;
			}			
		}

		if (widx < wildcard.length()) {
			char wild = wildcard.charAt(widx);
			switch (wild) {
			case '?':
				match(wildcard, widx + 1, fname, fidx + 1);
				break;
			case '*':
				match(wildcard, widx + 1, fname, fidx + 1);
				match(wildcard, widx, fname, fidx + 1);								
				break;
			default:
				if (wild == fname.charAt(fidx))
					match(wildcard, widx + 1, fname, fidx + 1);
				else {
					if (!isMatch)
						isMatch = false;
					return;
				}
			}
		} else {
			if (!isMatch)
				isMatch = false;
			return;
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ArrayList<String> list = new ArrayList<String>();
		int C = 0;
		if (scan.hasNextInt())
			C = scan.nextInt();
		
		// System.out.println(C);
		for (int i = 0; i < C; i++) {
			String W = null;
			if (scan.hasNext())
				 W = scan.next();
			// System.out.println(W);
			int N = 0;
			if (scan.hasNextInt())
				 N = scan.nextInt();
			// System.out.println(N);
			String fname;
			for (int j = 0; j < N; j++) {
				if (scan.hasNext()) {
					fname = scan.next();
					isMatch = false;
					match(W, 0, fname, 0);
					if (isMatch) {
						// System.out.println(fname);
						if (list.isEmpty())
							list.add(fname);
						else {
							int index = list.size();
							for (int k = 0 ; k < list.size(); k++) {								
								if (list.get(k).compareTo(fname) > 0) {
									index = k;
								}
							}
							list.add(index, fname);
						}
					}
				}
			}
			for (int k = 0; k < list.size(); k++)
				System.out.println(list.get(k));
			list.clear();
		}		
		scan.close();
	}
}
