n, m = map(int, input().split())
Min, price = 99999999, 0
for i in range(n):
    a, b = map(int, input().split())
    Min = min(Min, (a * m) / b)
print(price)
