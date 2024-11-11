# from debug import debug
import sys
mod = int(1e6)+7
inf = int(1e6)
con = ord('A')

n, m = map(int, input().split())
ma = [[0 for i in range(m)] for i in range(26)]
for i in range(n):
	s = input()
	for j in range(m):
		ma[ord(s[j])-con][j] = 1

ans = 1
for i in range(m):
	c = 0
	for j in range(26):
		c+=ma[j][i]
	ans = (ans*c)

print(ans%mod)

