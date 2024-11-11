a,b,k=map(int,input().split())
a=max(0,a-k)
b=max(0,b-(k-a))
print(a,b)