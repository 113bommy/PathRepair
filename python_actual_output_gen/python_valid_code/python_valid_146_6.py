def sum_digits(x):
    res = 0
    while x > 0:
        res += x % 10
        x //= 10
    return res

n  = int(input())
res  = []
for i in range(1, 82):
    if n - i + sum_digits(n-i) == n:
        res.append(n-i)
print(len(res))
for i in res:
    print(i)
