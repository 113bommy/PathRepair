t = int(input())

for ii in range(t):

	n = int(input())

	p = list(map(int, input().split()))

	print(*p[::-1])
