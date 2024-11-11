from math import ceil

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print((a + b + c + 1) % 2)
