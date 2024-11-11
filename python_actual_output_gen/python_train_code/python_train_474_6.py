import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))
diff=0
ma=0
for i in range(k,n+1):
    f=sum(a[:i+k])
    for j in range(n-k+1):
        if(j!=0):
            f-=a[j-1]
            f+=a[j]
        f=f/i
        ma=max(ma,f)
print(ma)
