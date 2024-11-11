import math

# n = int(input())

for _ in range(int(input())):
    # n = int(input())
    # a = list(map(int, input().split()))
    x, y = map(int, input().split())

    # if y <= x:
    if x > y:
        n = x + y
        print(n)
        continue
    if x == y:
        n = x
        print(n)
        continue
    if x < y:
        i = (y - x) // 2
        n = y - i
        print(n)
        continue

