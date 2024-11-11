N = 104723
p = [1]*(N + 1)
for i in range(4, N + 1, 2): p[i] = 0
a = [2]
for i in range(3, N + 1, 2):
    if p[i] == 1:
        a.append(a[-1] + i)
        for j in range(3*i, N + 1, 2*i): p[j] = 0

while True:
    n = int(input())
    if n == 0: break
    print(a[n - 1])