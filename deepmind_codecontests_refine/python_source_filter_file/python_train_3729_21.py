import sys
import bisect
n,m=map(int,input().split())
l=[[int(i) for i in l.split()] for l in sys.stdin]
s=[[0] for i in range(10**5+1)]
for i in l:
  s[i[0]].append(i[1])
for i in range(len(s)):
  s[i].sort()
for i in l:
  print('{:06}{:06}'.format(i[0],bisect.bisect_left(s[i[0]],i[1]))