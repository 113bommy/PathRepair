# import sys
# sys.stdin = open('cf598b.in')

s = list(input())
m = int(input())

for _ in range(m):
	l, r, k = map(int, input().split())
	if l != r:
		l -= 1
		r -= 1
		k %= r - l
		s[l:r+1] = s[r+1-k:r+1] + s[l:r+1-k]

print(''.join(s))