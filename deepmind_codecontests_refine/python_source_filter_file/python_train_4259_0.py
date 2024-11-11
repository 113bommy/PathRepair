import bisect
for e in iter(input,'0'):
 n=int(e)
 c=[sorted(int(input())for _ in[0]*n)]
 c+=[sorted(set(range(1,2*n+1))-set(c[0]))]
 t=f=0
 while 1:
  if not c[t]:break
  x=bisect.bisect(c[t],f)
  f=c[t].pop(x)if x<=len(c[t])else 0
  t^=1
 for i in[1,0]:print(len(c[i]))
