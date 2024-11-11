def ncr(n, r):
    return (fact(n) // ((fact(r)
                * fact(n - r))))
 
# Returns factorial of n
def fact(n):
    res = 1
    for i in range(2, n+1):
        res = res * i 
    return res
n,m,k = map(int,input().split())
mod = 998244353
a = ncr(n-1,k)
#print(a)
#print(2**3)
if k>=1:
    c = (m-1)**(k-1)
else:
    c = 1
c = c%mod
#print(c)
ans = a*m*c
print(ans%mod)