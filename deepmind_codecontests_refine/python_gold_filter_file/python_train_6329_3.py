n,k=map(int,input().split())
a,b=list(map(int,input().split())),0
for i,j in enumerate(a):
    for h in a[i:]:
        if j<h:b+=k*(k-1)//2
        elif j>h:b+=k*(k+1)//2
print(b%(10**9+7))