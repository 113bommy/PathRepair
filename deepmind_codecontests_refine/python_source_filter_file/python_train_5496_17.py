M = int(input())
s = 0
a = 0
for _ in range(M):
    d, c = map(int, input().split())
    s += d * c
    a += c
print(a - 1 + s // 10)