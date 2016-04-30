
diamond = [[x for x in range(100)] for y in range(100)]

def init_diamond(height, width):
	for y in range(height):
		for x in range(width):
			diamond[y][x] = 0

def print_diamond(height, width):
	for y in range(height):
		for x in range(width):
			print (diamond[y][x], end=" ")
		print()


if __name__ == '__main__':

	C = int(input())
	for i in range(0, C):
		N = int(input())
		init_diamond(2*N-1, N)
		for j in range(0, 2*N - 1):
			l = 0
			for k in input().strip().split():
				if j == 0 :
					diamond[j][l] = int(k)
				elif j < N:
					if l-1 < 0:
						diamond[j][l] = int(k) + diamond[j-1][l]
					else:
						diamond[j][l] = int(k) + max(diamond[j-1][l], diamond[j-1][l-1])
				elif j >= N:
					if l+1 > 100:
						diamond[j][l] = int(k) + diamond[j-1][l]
					else:
						diamond[j][l] = int(k) + max(diamond[j-1][l], diamond[j-1][l+1])
				l = l+1

		print(diamond[2*N-2][0])
		#print()
		#print_diamond(2*N-1, N)
		#print()
