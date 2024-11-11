import sys,random
try: sys.stdin = open('in.in','r')
except: pass

ans = 0
allboth = 1
l = r = 0

n = int(input())
for i in range(n):
	s = input().strip()
	ans += s.count('AB')
	if s[0] == 'B' or s[-1] == 'A':
		l += s[0] == 'B'
		r += s[-1] == 'A'
		if s[0] != 'B' or s[-1] != 'A':
			allboth = 0

ans += min(l,r)
if allboth and ans: ans -= 1
print(ans)
