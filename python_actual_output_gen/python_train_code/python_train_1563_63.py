import sys
input = sys.stdin.readline
for _ in range(int(input())):
	n = int(input())
	if n == 2 or n==1:
		print(0)
		break
	print((n-1)//2)