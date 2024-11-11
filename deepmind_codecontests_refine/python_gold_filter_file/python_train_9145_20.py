K,T=map(int,input().split())
a=list(map(int,input().split()))
t=max(a)
print(max(t-1-(K-t),0))