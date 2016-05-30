import java.io.IOException;

/**
 * @author Steven
 *
 */
public class Main {
	public static String str;

	public static String doReverse(int start) {
		// System.out.println(start + " " + end + " " + str);
		// System.out.println(input.substring(0, 2));

		String reverse = "";
		if (str.charAt(start) == 'w') {
			reverse += 'w';
			return reverse;
		}
		if (str.charAt(start) == 'b') {
			reverse += 'b';
			return reverse;
		}

		String str1 = "", str2 = "", str3 = "", str4 = "";
		if (str.charAt(start) == 'x') {
			str1 = doReverse(start + 1);
			// System.out.println(str1);
			str2 = doReverse(start + 1 + str1.length());
			// System.out.println(str2);
			str3 = doReverse(start + 1 + str1.length() + str2.length());
			// System.out.println(str3);
			str4 = doReverse(start + 1 + str1.length() + str2.length() + str3.length());
			// System.out.println(str4);
			// reverse = str3.concat(str4).concat(str1).concat(str2);
		}
		reverse = "x".concat(str3).concat(str4).concat(str1).concat(str2);
		return reverse;
		// return reverse = str3 + str4 + str1 + str2;
	}

	public static void main(String[] args) throws IOException {
		int testcase = 0;
		char ch;
		testcase = (int) System.in.read() - '0';
		while ((ch = (char) System.in.read()) != '\n') {
		}

		for (int i = 0; i < testcase; i++) {
			str = "";

			int strLen = 0;
			int maxLen = 1;
			while (strLen != maxLen) {
				ch = (char) System.in.read();
				str += ch;
				if (ch == 'x') {
					maxLen += 4;
				}
				strLen++;
			}
			
			if (i != testcase - 1) {
				while ((ch = (char) System.in.read()) != '\n') {
				}
			}
			
			//System.out.println(maxLen);
			//System.out.println(strLen);

			/*
			 * while ((ch = (char) System.in.read()) != '\n') { str += ch; }
			 */
			String reverse = doReverse(0);
			if (i != testcase - 1) {
				System.out.println(reverse);
			} else {
				System.out.print(reverse);
			}
		}
	}
}
