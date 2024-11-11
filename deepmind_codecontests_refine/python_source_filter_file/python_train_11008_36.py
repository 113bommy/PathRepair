n = int(input())
res = 0
for d in [100, 20, 10, 5, 1]:
    res += n//d
    n -= res * d
print(res)