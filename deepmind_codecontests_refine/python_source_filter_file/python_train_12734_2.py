import sys

input = sys.stdin.readline

def solve():
	n, q = map(int, input().split())
	s = input().strip()
	p = [0]*(n+1)
	A = ord('a')
	for i in range(n):
		p[i+1] = p[i] + ord(s[i]) - A + 1
	print(p)
	for i in range(q):
		l, r = map(int, input().split())
		print(p[r]-p[l-1])

#for in range(int(input())):
solve()
