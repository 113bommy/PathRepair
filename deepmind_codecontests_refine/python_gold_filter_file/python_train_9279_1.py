n,x,y=map(int,input().split())
n-=1
t=y-n
print(['1\n'*n+str(t),-1][t<1 or t*t+n<x])