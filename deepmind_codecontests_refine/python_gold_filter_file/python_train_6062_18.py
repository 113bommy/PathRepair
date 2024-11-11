"""import sys
sys.stdin = open("marks.in","r")"""
a = int(input())
for x in range(a):
	b = list(map(int,input().split()))
	c = list(map(int,input().split()))

	if b[0] > 1:
		if b[1] - c[0] <= sum(c) - c[0]:
			print(b[1])
		else:
			print(sum(c))
	else:
			print(c[0])			