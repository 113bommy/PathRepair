n, m = map(int, input().split())
l = [0]*102
for i in range(m):
    a, b, c = map(int, input().split())
    l[a] += c
    l[b] -= c
sum = 0
for i in range(n):
    if l[i] > 0:
        sum += l[i]
print(sum)
