n,d=list(map(int,input().split()))
a=list(map(int,input().split()))
b=0
for i in range(1,n):
    if a[i-1]>=a[i]:
        c=a[i-1]-a[i]
        b+=c//d
        a[i]+=c//d*d
        b+=1
        a[i]+=d
print(b)