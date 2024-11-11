M = int(input())
X = [list(map(int, input().split())) for _ in range(M)]

d = sum(c for _, c in X)
s = sum(d for d, _ in X)
print(d - 1 + (s - 1) // 9)
