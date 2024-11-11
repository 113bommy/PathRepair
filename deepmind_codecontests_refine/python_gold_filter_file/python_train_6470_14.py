n = int(input())
s = input()
n -= 10
s = s[:n]

if s.count('8') >= n//2 + 1:
	print('YES')
else: print('NO')
