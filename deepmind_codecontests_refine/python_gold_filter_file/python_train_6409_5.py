def R():
    return map(int, input().strip().split())
n, m, k = R()
x, s = R()

t1 = list(R())
m1 = list(R())
t2 = list(R())
m2 = list(R())

h = []
for i in range(len(m1)):
    if s-m1[i] >= 0:
        h.append([t1[i], s-m1[i]])
h.sort(key = lambda x: x[1])

so_far = None
j = 0
ans = n*x
for i in range(len(h)):
    while j < len(m2) and m2[j] <= h[i][1]:
        so_far = j
        j += 1
    if so_far is not None:
        ans = min(ans, (n-t2[so_far])*h[i][0])
    ans = min(ans, n*h[i][0])

for i in range(len(m2)):
    if m2[i] <= s:
        ans = min(ans, (n-t2[i])*x)
print(ans)
