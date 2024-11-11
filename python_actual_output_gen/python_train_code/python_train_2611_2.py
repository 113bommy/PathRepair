import sys
v=[0]*101
for e in sys.stdin:
 a,b=map(int,e.split())
 if a==0:
  print(['ng','ok'][1&v[1]and 1&v[2]and sum(x&1 for x in v[3:])==0])
  v=[0]*101
 v[a]+=1;v[b]+=1
