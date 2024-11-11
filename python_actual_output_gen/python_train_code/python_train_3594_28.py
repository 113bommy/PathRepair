k, n, w = map(int, input().split())
cost = k
for number in range(2, w + 1):
    cost += (number * k)
print(cost - n)
