n,m,r=map(int,input().split())
s=min(list(map(int,input().split())))
b=max(list(map(int,input().split())))
res,m=(r//s)*b,r%s
print(max(res,r)+m)