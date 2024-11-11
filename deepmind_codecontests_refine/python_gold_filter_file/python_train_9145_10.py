k,t=map(int,input().split())
a=list(map(int,input().split()))
m=max(a)
print(max(m-1-(k-m),0))