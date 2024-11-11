n,k=map(int,input().split())
x=[0]*n
y=[0]*n
a=[]
for i in range(n):
  x[i],y[i]=map(int,input().split())
  a.append((x[i],y[i]))
ans=4*(10**18)
x.sort()
y.sort()
for i in range(n-1):
  for j in range(i+1,n):
    for l in range(n-1):
      for m in range(l+1,n):
        L=x[i]
        R=x[j]
        D=y[l]
        U=y[m]
        if L==R or U==D:
          continue
        cnt=0
        for s in a:
          if L<=s[0]<=R and D<=s[1]<=U:
            cnt+=1
        if cnt>=k:
          ans=min(ans,(R-L)*(U-D))
print(ans)