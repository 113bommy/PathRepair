n = int(input())
xi = list(map(int, input().split()))

p = round(sum(xi) / n)
hp = 0
for x in xi:
    hp += (x - p) ** 2

print(hp)