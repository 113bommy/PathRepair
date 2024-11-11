n = int(input())
a = list(map(int, input().split()))

m = {1: 0, 2: 0, 3: 0, 4: 0}
c = 0

for i in a:
    m[i] += 1

c += m[4]

c += m[3]
if m[1] >= m[3]:
    m[1] -= m[3]
else:
    m[1] = 0

c += m[2] // 2
if m[2] % 2 == 1:
    c += 1
    m[1] -= min(m[1], 2)

c += m[1] // 4

if 4 > m[1] > 0:
    c += 1
if c == 33334:
    print(m)

print(c)
