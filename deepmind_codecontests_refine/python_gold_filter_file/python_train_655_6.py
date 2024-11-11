import sys
input = sys.stdin.readline

for nt in range(int(input())):
	n = int(input())
	a = list(map(int,input().split()))
	s = sum(a)
	a = s%n
	b = n - a
	print (a*b)