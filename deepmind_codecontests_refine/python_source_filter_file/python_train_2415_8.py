def gcd(a, b):
    while b > 0:
        c = a % b
        a = b
        b = c

    return a

n = int(input())
i = 2
divisors = list()
g = n

while i * i <= n:
    if n % i == 0:
        g = gcd(g, i)        
        g = gcd(g, n / i)        
    i += 1

print(g)        