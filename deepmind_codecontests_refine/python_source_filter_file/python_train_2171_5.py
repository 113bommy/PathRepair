A,B,C=map(int,input().split())
if A == B == C:
	print((A % 2) - 1)
else:
	i = 0
	while (A % 2) == (B%2) == (C%2==0):
		A,B,C = (B//2) + (C//2), (C//2) + (A//2), (A//2) + (B//2)
		i += 1
	print(i)
