n,k = map(int,input().split())
a = list(map(int,input().split()))
for i in range(1,n*2+1,2):
    if k==0:
        break
    if a[i]>a[i-1] and a[i]>a[i+1]:
        a[i]-=1
        k-=1
print(*a)
