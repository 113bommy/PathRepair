a,s=map(int,input().split())
k,m=map(int,input().split())
f = list(map(int, input().split()))
b = list(map(int, input().split()))
if (f[k-1]<b[s-m]):
    print  ("YES")
else:
    print("NO")