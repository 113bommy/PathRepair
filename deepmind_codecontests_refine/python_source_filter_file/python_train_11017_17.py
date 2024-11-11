n=int(input())
a=[int(i) for i in input().split()]
k,m=0,abs(a[0])
for i in range(1,n):
    if abs(a[i])>m:
        m=abs(a[i])
        k=i
print(2*n-1)
for i in range(n):
    print(k+1,i+1)
if a[k]>=0:
    for i in range(1,n):
        print(i,i+1)
else:
    for i in range(1,n):
        print(n-i,n-i-1)

