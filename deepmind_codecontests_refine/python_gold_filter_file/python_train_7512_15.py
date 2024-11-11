n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
tot=a[-1]-a[0]
n-=1
k-=1
for i in range(n):
    a[i]=a[i+1]-a[i]
a.sort(reverse=1)
# print(a)
for i in range(1,k+1):
    tot-=a[i]
print(tot)