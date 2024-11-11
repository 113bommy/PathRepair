import sys
input = sys.stdin.readline

q=int(input())

for i in range(q):
	l1,r1,l2,r2=map(int,input().split())

	if l1<r2:
		print(l1,r2)
	else:
		print(r1,l2)