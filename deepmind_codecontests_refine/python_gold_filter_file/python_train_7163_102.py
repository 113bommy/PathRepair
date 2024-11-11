n,a,b=map(int,input().split())
high=min(a,b)
low=max(0,a+b-n)
print(high,low)