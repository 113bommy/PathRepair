a,b,k=map(int,input().split())
t=max(0,a-k)
ao=(b if a>=k else b-(k-a))
print(t,ao)
