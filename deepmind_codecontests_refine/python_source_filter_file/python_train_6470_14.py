n = int(input())
s = input()
n -= 11
s = s[:2*n]

if s.count('8') >= n//2:
	print('YES')
else: print('NO')
