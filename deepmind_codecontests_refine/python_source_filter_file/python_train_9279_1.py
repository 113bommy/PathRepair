n,x,y=map(int,input().split())
n-=1
t=y-n
print(['1\n'*n+str(t),-1][t*t+n<x])