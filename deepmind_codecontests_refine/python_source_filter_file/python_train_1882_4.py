def f():
 for c in range(n):
  for d in a[c+1:]:
   for p in([0,1,2,3,4,5],[1,5,2,0,4,3],[2,1,5,3,0,4],[3,0,2,5,4,1],[4,1,0,3,5,2],[5,1,4,3,2,0]):
    if[d[p[0]],d[p[5]]]==a[c][::5]:
     b=[d[i]for i in p[1:5]]
     for k in range(4):
      if b[k-4:k-1]==a[c][1:5]:return"No"
 return"Yes"
n=int(input())
a=[input().split()for _ in[0]*n]
for b in a:b[3:5]=b[4],b[3]
print(f())
