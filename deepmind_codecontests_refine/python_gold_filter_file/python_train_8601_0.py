k, p = [int(i) for i in input().split()]
l2 = [(11*i) % p for i in range(1,10)]
l4 = [(1001*i + 110 * j) % p for i in range(1,10) for j in range(10)]
l6 = [(100001*i + 10010 * j + 1100 * k) % p for i in range(1,10) for j in range(10) for k in range(10)]
l8 = [(10000001*i + 1000010 * j + 100100 * k + 11000 * x) % p for i in range(1,10) for j in range(10) for k in range(10) for x in range(10)]
l10 =  [(1000000001*i + 100000010 * j + 10000100 * k + 1001000 * x + 110000 * y) % p for i in range(1,10) for j in range(10) for k in range(10) for x in range(10) for y in range(10)]
l = l2 + l4 + l6 + l8 + l10 + [100000000001]
print(sum(l[:k]) % p)