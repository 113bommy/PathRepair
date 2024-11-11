from sys import stdin, stdout
import math

def main():
	line = stdin.readline().split()
	n = int(line[0])
	q = int(line[1])
	c = int(line[2])

	dp = [[ [0 for i in range(101)] for j in range(101)] for k in range(11)]
	
	for i in range(n):
		line = stdin.readline().split()
		x = int(line[0])
		y = int(line[1])
		p = int(line[2])
		dp[p][x][y] += 1

	for p in range(0, c+1):
		for x in range(1, 101):
			for y in range(1, 101):
				dp[p][x][y] += (dp[p][x-1][y]+dp[p][x][y-1]-dp[p][x-1][y-1])

	for i in range(q):
		line = stdin.readline().split()
		t = int(line[0])
		x1 = int(line[1])
		y1 = int(line[2])
		x2 = int(line[3])
		y2 = int(line[4])
		ans = 0
		for j in range(c+1):
			bright = (j+t)%(c+1)
			amount = dp[j][x2][y2]-dp[j][x1][y1-1]-dp[j][x1-1][y1]+dp[j][x1-1][y1-1]
			ans += (bright*amount)
		stdout.write(str(ans)+"\n")

if __name__ == '__main__':
	main()