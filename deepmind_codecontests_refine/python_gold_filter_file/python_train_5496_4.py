M = int(input())

D, S = 0, 0

for _ in range(M):
    d, c = map(int, input().split())
    D += c
    S += d * c

print(D - 1 + (S - 1) // 9)
