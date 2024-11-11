
results = []
for i in range(int(input())):
    x, y = (map(int, input().split()))
    n = y
    prms = []
    if x % y:
        results.append(x)
        continue
    i = 2
    while i*i <= n:
        if n % i == 0:
            prms.append(i)
            while n % i == 0:
                n //= i
        i += 1
    if n > 1:
        prms.append(n)
    
    biggest = 0
    for fac in prms:
        m = x
        m //= fac
        while m % y == 0:
            m //= fac
        biggest = max(m, biggest)
    results.append(m)

for r in results:
    print(r)    
