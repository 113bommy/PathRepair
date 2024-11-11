n = int(input())
shortest = 0
for loop in range(n):
    x, y = map(int, input().split())
    side = x + y
    if side > shortest:
        shortest = side
print(side)
