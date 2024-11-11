n,m=map(int, input().split())
mi=1
mx=n
for i in range(m):
    a,b=map(int, input().split())
    mi=max(a,mi)
    mx=min(mx,b)
print(mx-mi+1)