n,m=map(int,input().split())
a,b=map(int,input().split())
mini=round(b/a,8)
for i in range(n-1):
    a,b=map(int,input().split())
    if mini>a/b:
        mini=a/b
print(round(m*mini,8))