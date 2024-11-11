def sum(a):
    s=0
    for i in a:
        s=s+i
    return s
n,m=map(int,input().split())
a=list(map(int,input().split()))
print("YES" if sum(a)-a[len(a)-1]<=m else "NO")