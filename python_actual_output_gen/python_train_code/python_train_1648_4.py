n, k = map(int, input().split())
d = []
i = 1
while i * i < n:
    if n % i == 0:
        d.append(i)
        d.append(n // i)
    i += 1
d.sort()
for i in range(len(d) - 1, -1, -1):
    ari = (1 + k) / 2 * k
    if ari <= n // d[i]:
        for j in range(1, k):
            print(j * d[i], end = " ")
        print(int((n // d[i]) - ari + k) * d[i])
        exit()
print(-1)
        
        