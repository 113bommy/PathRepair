def gcd(a,b):
    if(a==0):
        return b
    return gcd(b%a,a)

n,m = map(int,input().split())
X = list(map(int,input().split()))
P = list(map(int,input().split()))
a = 0
for i in range(1,n):
    a = gcd(a,X[i]-X[i-1])
f=0
for i in range(m):
    if(P[i]==a):
        print("YES")
        print(X[0],i+1)
        f=1
        break
if(f==0):
    print("NO")