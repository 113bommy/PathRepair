import sys
v=[0]*101
for e in sys.stdin:
 a,b=map(int,e.split())
 v[a]+=1;v[b]+=1
 if a==0:
  print(['NG','OK'][v[1]&1*v[2]&1*sum(x&1 for x in v)==2])
  v=[0]*101
