n = int(input())
c = 0
for i in range(n):
    s, d =map(int, input().split())
    if c < s:
        c = s
    else:
        c = s + ((c - s - 1) // d + 1) * d
print(c)