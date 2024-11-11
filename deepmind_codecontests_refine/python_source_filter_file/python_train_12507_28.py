n = int(input())
d = [0] * 10005
for i in range(n):
    a, b = map(int, input().split())
    for j in range(a, b + 1):
        d[j] = i
c = int(input())
print(n - d[c - 1])
