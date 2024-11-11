
t = int(input())
MOD = 1000000007
for _ in range(t):
    n = int(input())

    fact = 1
    for i in range(1, 2*n+1):
        fact = (fact * i) % MOD
    print((fact//2) % MOD)
