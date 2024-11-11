t = int(input())
for _ in range(t):
    [a, b] = [int(x) for x in input().split()]
    diff = abs(a - b)
    count = diff // 10
    count += 1 if diff % 10 > 0 else 0
    print("ans", count)

