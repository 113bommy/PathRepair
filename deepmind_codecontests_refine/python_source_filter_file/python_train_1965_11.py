import sys
m=10**6;a=[1]*m;a[0:2]=0,0
for i in range(2,999):
 if a[i]>0:
  for j in range(i*2,,i):a[j]=0
for i in range(m):a[i]+=a[i-1]
for e in sys.stdin:print(a[int(e)])
