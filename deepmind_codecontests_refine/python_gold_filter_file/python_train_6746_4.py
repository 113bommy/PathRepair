n=int(input())
import bisect

a=[-int(input()) for _ in range(n)]
x=[a[0]]
for i in a[1:]:
  y=bisect.bisect(x,i)
  if y==len(x):x.append(i)
  else:x[y]=i
print(len(x))