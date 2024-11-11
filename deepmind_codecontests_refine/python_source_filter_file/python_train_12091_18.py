n,m,k=map(int,input().split())
lis=list(map(int,input().split()))
x=max(lis)
lis[lis.index(x)]=-1
y=max(lis)
print(((k*x+y)*(m//(k+1)))+m%(k+1))
