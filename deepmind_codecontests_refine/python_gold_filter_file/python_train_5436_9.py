import math 

mod = 10**9 + 7 

def tarkib(n , k ):
    return math.factorial(n) // (math.factorial(n-k) * math.factorial(k))


n , m = map(int , input().split())

print(tarkib(n+2*m-1,2*m) % mod)


