n = int(input())
S = input()

if S[:n//2] == S[n//2:]:
	print('Yes')
else:
	print('No')