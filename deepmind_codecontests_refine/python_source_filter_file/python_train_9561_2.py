n,k=map(int,input().split())
l=[list(map(int,input().split())) for i in range(n)]
x=[l[i][0] for i in range(n)]
x.sort()
y=[l[i][1] for i in range(n)]
y.sort()
ans=[]
for i1 in range(n):
  for i2 in range(n):
    for i3 in range(n):
      for i4 in range(n):
        ct=0
        for i5 in range(n):
          if min(x[i1],x[i2])<=l[i5][0]<=max(x[i1],x[i2]) and min(y[i3],y[i4])<=l[i5][1]<=max(y[i3],y[i4]):ct+=1
        if ct>=k:
          ans.append(abs(x[i1]-x[i2])*abs(y[i3]-y[i4]))
print(min(ans))