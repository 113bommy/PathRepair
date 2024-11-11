mod = 998244353

def mul(a, b):
    return ((a % mod) * (b % mod)) % mod

def div(a, b):
    return mul(a, power(b, mod-2))
def div2(a, b):
    return mul(a, modinv(b))


pwt = [1]
for i in range(2*10**5):
    pwt.append((pwt[-1]*10)%mod)
#print(pwt)


N = int(input())
R = []
for i in range(1, N+1):
    if N-i >= 2:
        x = mul(10*9*9*pwt[N-i-2]%mod, N-i-2)
        y = mul(10*9*pwt[N-i-1]%mod, 2)
    elif N-i == 1:
        x = 0
        y = mul(10*9*pwt[N-i-1]%mod, 2)
    else:
        x = 0
        y = 10
    R.append((x+y)%mod)
print(*R)
