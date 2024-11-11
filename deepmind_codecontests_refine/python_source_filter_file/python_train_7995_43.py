n,m=map(int,input().split())
x=list(map(int,input().split()))
x.sort()
a=[x[i+1]-x[i]for i in range(m-1)]
if m<=n:print(0);exit()
a.sort()
print(sum(a[:m-n+1]))