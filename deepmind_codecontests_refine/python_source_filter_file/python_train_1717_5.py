n,k,l,MOD = map(int, input().split())

class Matrix:
    def __init__(self, a,b,c,d):
        self.a, self.b, self.c, self.d = a,b,c,d
    def __mul__(self, other):
        return Matrix(
                      (self.a * other.a + self.b * other.c) % MOD, 
                      (self.a * other.b + self.b * other.d) % MOD,
                      (self.c * other.a + self.d * other.c) % MOD,
                      (self.c * other.b + self.d * other.d) % MOD
                     ) 


def bin_pow(base, deg):
    if deg == 0:
        return Matrix(1,0,0,1)
    tmp = bin_pow(base, deg // 2)
    tmp =  tmp * tmp
    if deg % 2 == 1:
        tmp *= base
    return tmp

def Fib(n):
    return bin_pow(Matrix(1,1,1,0), n).b

without_set = Fib(n+2)
with_set = (pow(2, n, MOD) + MOD - without_set) % MOD

if k >= 2**l: 
    print(0)
    exit(0)
ans = 1

for i in range(l):
    x = k % 2;
    k //= 2
    if x:
        ans *= with_set
    else:
        ans *= without_set
    ans %= MOD
    
print(ans)
