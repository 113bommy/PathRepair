n=int(input())
a=[int(j) for j in input().split()]
t=1
mod=10**9+7
def gcd(x,y):
    if y==0:
        return x
    else:
        return gcd(y,x%y)
for i in a:
    t*=i//gcd(t,i)
print(sum(t//i for i in a)%mod)