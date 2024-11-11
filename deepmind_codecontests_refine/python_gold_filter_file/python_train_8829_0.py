n = int(input())
a = list(map(int, input().split()))

a = sorted([r - (i + 1) for i, r in enumerate(a)])
b = a[(n - 1) // 2]

print(sum([abs(r - b) for r in a]))
