nmk = [int(i) for i in input().split()]
n = nmk[0]
m = nmk[1]
k = nmk[2]
x = []
ans = 0
for i in range(m):
    x.append(int(input()))
s = int(input())
s_bits = []
for i in range(n):
    s_bits.append(s % 2)
    s //= 2
for i in range(m):
    x_bits = []
    for j in range(n):
        x_bits.append(x[i] % 2)
        x[i] //= 2
    t = 0
    for j in range(n):
        if x_bits[j] != s_bits[j]:
            t += 1
    if t <= k:
        ans += 1
print(ans)


