import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {	
	
	//public class Board {
		private int height;
		private int width; 
		private int posx;
		private int posy;
		private int empty;
		private char[][] board = new char[20][20];
		
		public Main(int h, int w) {
			height = h;
			width = w;
			posx = 0;
			posy = 0;
			empty = height * width;
			init_board(h, w);
		}
		
		public Main(Main b) {
			
			height = b.height;
			width = b.width;
			posx = b.posx;
			posy = b.posy;
			empty = b.empty;
			//init_board(height, width);
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					board[y][x] = b.board[y][x];
				}
			}		
		}
		
		public void set_height(int h) {
			height = h;
		}
		
		public void set_width(int w) {
			width = w;
		}
		
		public int get_posx() {
			return posx;
		}
		
		public int get_posy() {
			return posy;
		}
		
		public int get_empty() {
			return empty;
		}
		
		private void init_board(int h, int w) {
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					board[y][x] = '#';
				}
			}
		}
		
		public void set_board(int y, int x, char v) {
			if (v == '#')
				empty--;
			board[y][x] = (char) v;
		}
		
		public void print_board() {
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					System.out.print(board[y][x]);
				}
				System.out.print('\n');
			}
		}
		
		public boolean is_validate(int y, int x) {
			if (y < 0 || y > height)
				return false;
			if (x < 0 || x > width)
				return false;
			if (board[y][x] == '#')
				return false;
			return true;
		}
		
		public int set_boardcover(int y, int x, int type) {
			switch (type) {
			case 1:
				// ##
				// #
				// System.out.println(y + " " + x);
				if (!is_validate(y, x))
					return -1;
				if (!is_validate(y, x+1))
					return -1;
				if (!is_validate(y+1, x))
					return -1;
				set_board(y, x, '#');
				set_board(y, x+1, '#');
				set_board(y+1, x, '#');
				break;
				
			case 2:
				// ##
				//  #
				if (!is_validate(y, x))
					return -1;
				if (!is_validate(y, x+1))
					return -1;
				if (!is_validate(y+1, x+1))
					return -1;
				set_board(y, x, '#');
				set_board(y, x+1, '#');
				set_board(y+1, x+1, '#');
				break;
				
			case 3:
				// #
				// ##
				if (!is_validate(y, x))
					return -1;
				if (!is_validate(y+1, x))
					return -1;
				if (!is_validate(y+1, x+1))
					return -1;
				set_board(y, x, '#');
				set_board(y+1, x, '#');
				set_board(y+1, x+1, '#');			
				break;
				
			case 4:
				//  #
				// ##
				if (!is_validate(y, x))
					return -1;
				if (!is_validate(y+1, x))
					return -1;
				if (!is_validate(y+1, x-1))
					return -1;
				set_board(y, x, '#');
				set_board(y+1, x, '#');
				set_board(y+1, x-1, '#');
				break;
				
			case 5:
				//  #
				// ##
				if (!is_validate(y, x))
					return -1;
				if (!is_validate(y, x+1))
					return -1;
				if (!is_validate(y-1, x+1))
					return -1;
				set_board(y, x, '#');
				set_board(y, x+1, '#');
				set_board(y-1, x+1, '#');
				break;
				
			default:
				break;
			}
			return 0;
		}
		
		public int update_pos() {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (i == height -1 && j == width -1)
						return -1;
					if (board[i][j] == '.') {
						posx = j;
						posy = i;
						//System.out.println(posx + " " + posy);
						return 0;
					}
				}
			}
			return 0;
		}
	//}

	
	public static void main(String[] args) throws IOException {
		int tc, h, w, rc, count;
		Main board;
		
		Scanner sc = new Scanner(System.in);      	
		ArrayList<Main> arraylist = new ArrayList<Main>();		
		
		tc = sc.nextInt();		
		
		for (int i = 0; i < tc; i++) {			
			h = sc.nextInt();
			w = sc.nextInt();
			count = 0;
			board = new Main(h, w);
			
			sc.nextLine();
			
			for (int j = 0; j < h; j++) {
				String str = sc.nextLine();
				for (int k = 0; k < w; k++)
					board.set_board(j, k, str.charAt(k));
			}		
			
			//System.out.println(board.get_empty() % 3);			
			if (board.get_empty() == 0)
				count = 1;
			
			if (board.get_empty() % 3 == 0) {
				arraylist.add(board);
			}
			
			while (!arraylist.isEmpty()) {				
				for (int k = 1; k <= 5; k++) {
					Main temp = new Main(arraylist.get(0));
					temp.update_pos();
					//System.out.println(temp.get_posy() + " " + temp.get_posx());
					//System.out.println("k (" + k + ") e (" + temp.get_empty() + ")");
					rc = temp.set_boardcover(temp.get_posy(), temp.get_posx(), k);
					//System.out.println("k (" + k + ") e (" + temp.get_empty() + ") r (" + rc + ")");
					//temp.print_board();
					if (rc == 0) {
						if (temp.get_empty() == 0) {
							count++;
							temp = null;
						} else {
							arraylist.add(temp);
						}
					} else {
						temp = null;
					}
				}
				arraylist.remove(0);
			}
			System.out.println(count);
		}
	}
}