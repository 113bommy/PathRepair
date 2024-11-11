n,k=map(int,input().split())
a,b=list(map(int,input().split())),0
for i,j in enumerate(a):
    for h in a[i:]:
        if i<h:b+=k*(k-1)//2
        else:b+=k*(k+1)//2
print(b%(10**9+7))