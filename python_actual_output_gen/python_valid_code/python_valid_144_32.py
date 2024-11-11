n,c=map(int,input().split())
a=list(map(int,input().split()))
r=0
for i in range(1,n):
    if a[i]-a[i-1]<=c:
        r+=1
    else:
        r=0
print(r)
