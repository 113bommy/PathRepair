a,b=map(int,input().split())
print(min(a,b),end=" ")
d=max(a,b)-min(a,b)
print(d%2)