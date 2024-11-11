n,k = map(int,input().split())
a = list(map(int,input().split()))
for i in range(1,n+1):
    if k-i>=0:
        k = k-i
    else:
        break
print(a[k-1])
