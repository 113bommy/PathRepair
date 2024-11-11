n=int(input())
a=list(map(int,input().split()))
res=a[-1]
for i in range(n-3,-1,-1):
    res+=min(a[i],a[i+1])
print(res+a[0])