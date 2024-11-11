#codeforces_1015B_live
from collections import Counter
gi = lambda: list(map(int,input().split(" ")))
n, = gi()
s,t = input(),input()
if s == t:
	print(0)
	exit();
for e in s:
	if e not in t or s.count(e) != t.count(e):
		print(-1)
		exit();
ans = 0
rez = []
for k in range(n):
	if s[k] != t[k]:
		ind = s.index(t[k])
		ans += ind - k
		rez.append(" ".join(map(str,range(ind,k,-1))))
		s = s[:k]+s[ind]+s[k:ind]+s[ind+1:]
print(ans)
print(" ".join(rez))