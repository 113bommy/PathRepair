n, m = map(int, input().split())
s = str(input())
a = [int(i) for i in s.split()]
b = [0] * 200001
c = [0] * 200001

a.sort()

for elem in a:
    b[elem] += 1
    count = 0
    while elem != 0 and b[elem // 2] < m:
        elem //= 2
        count += 1
        c[elem] += count
        b[elem] += 1

ans = 10000000000
for i in range(len(b)):
    if b[i] == m:
        if ans > c[i]:
            ans = c[i]
print(ans)
