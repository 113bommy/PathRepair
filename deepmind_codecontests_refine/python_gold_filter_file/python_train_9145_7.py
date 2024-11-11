k,t=map(int,input().split())
a=list(map(int,input().split()))
m=max(a)
n=k-m
print(max(m-n-1,0))