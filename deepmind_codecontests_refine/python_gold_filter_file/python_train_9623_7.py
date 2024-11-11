n = int(input())
p = map(int, input().split())
f = list(range(n+1))
for i in range(1, n + 1):
    f[i] ^= f[i-1]
sum = 0
for i in p:
    sum ^= i
c = []
c.append(0)
for i in range(1, n + 1):
    if (n // i) & 1:
        c.append(f[i - 1] ^ f[n % i])
    else:
        c.append(f[n % i])
    sum ^= c[i]
print(sum)