digit = 0
s = 0

M = int(input())
for _ in range(M):
    d, c = map(int, input().split())
    digit += c
    s += d * c

x = digit - 1
y = s // 9 - (s % 9 == 0)
print(x + y)
