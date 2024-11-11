# import sys
# sys.stdin = open("#input.txt", "r")

for _ in range(int(input())):
	n = int(input())
	p2sum = 0
	i = 1
	while i<=n:
		p2sum += i
		i <<= 1
	print((n*(n+1))//2 - 2*p2sum)