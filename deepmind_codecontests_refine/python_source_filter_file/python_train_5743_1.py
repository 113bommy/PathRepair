#import numpy as np 

def main():
	n, m = list(map(int, input().split()))
	l1 = [[0] * m for index in range(n)]
	l2 = [[0] * m for index in range(n)]
	for i in range(0, n):
		l1[i] = list(map(int, input().split()))
	for i in range(0, n):
		l2[i] = list(map(int, input().split()))
	#print(l1, l2)
	for i in range(0, n):
		for j in range (0, m):
			x = l1[i][j]
			y = l2[i][j]
			l1[i][j] = min(x, y)
			l2[i][j] = max(x, y)
	ans = "Possible"
	for i in range(0, n):
		for j in range(0, m):
			if i > 0 and l1[i][j] <= l1[i-1][j]:
				ans = "Impossible"
			if j > 0 and l1[i][j] <= l1[i][j-1]:
				ans = "Impossible"
	for i in range(1, n):
		for j in range(1, m):
			if i > 0 and l2[i][j] <= l2[i-1][j]:
				ans = "Impossible"
			if j > 0 and l2[i][j] <= l2[i][j-1]:
				ans = "Impossible"
	#print(l1)
	#print(l2)
	print(ans)

if __name__ == '__main__':
	main()

