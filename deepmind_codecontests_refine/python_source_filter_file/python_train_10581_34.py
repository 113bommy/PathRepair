n,m=map(int,input().split())
a,b=map(int,input().split())
mini=round(b/a,8)
for i in range(n-1):
    a,b=map(int,input().split())
    if mini>b/a:
        mini=b/a
print(round(m*mini,8))