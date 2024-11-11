n = int(input())
d, d_sum = 0, 0
for _ in range(n):
    a, b = map(int, input().split())
    d += b
    d_sum += a * b

print(d - 1 + d_sum // 9)
