n,m=map(int,input().split())
a=1
for _ in range(m):
    l,r=map(int,input().split())
    if n>r:n=r
    if a<l:a=l
print(n-a+1) if n-a>=0 else print(0)
