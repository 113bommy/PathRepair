n, a, b = map(int, input().split())
coins = list(map(int, input().split()))
for i in range(n):
    coins[i] = (coins[i] * a) % b
print(*coins)