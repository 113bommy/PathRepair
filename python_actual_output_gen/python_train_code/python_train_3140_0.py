k,t=map(int,input().split())
a=list(map(int,input().split()))
m=max(a)
n=k-m
print(min(m-n-1,0))