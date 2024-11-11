def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

if n==1:
    for i in range(m):
        print(a[0]+b[i],end=" ")
    print()
else:
    temp = a[1]-1
    for i in range(2,n):
        temp = gcd(temp,a[i]-1)
    for j in range(m):
        print(gcd(temp,a[0]+b[j]),end=" ")
    print()