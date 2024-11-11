n, k = map(int, input().split())

res = 0
while k > 0:
    res += 1
    k //= 2

print(res)
