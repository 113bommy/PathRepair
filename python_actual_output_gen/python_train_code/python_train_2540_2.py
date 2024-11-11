n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    a[i]=i+1-a[i]
b=1
m=a[-1]
for i in range(n-2,0,-1):
    if i+1<m:
        b+=1
    m=min(a[i],m)
print(b)