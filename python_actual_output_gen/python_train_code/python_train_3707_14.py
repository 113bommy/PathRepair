n = int(input())
p = 2
ans = 0
while n > 1:
    if p > 10 ** 6:
        ans = 1
        break
    e = 1
    while n % (p ** e) == 0:
        n = n // (p ** e)
        e += 1
        ans += 1
    while n % p == 0:
        n = n // p
    p += 1
    
print(ans)