n, k = [int(i) for i in input().split()]
l = [int(i) - 1 for i in input().split()]

i = 0
m = [-1] * n
p = 0

while m[i] == -1:
    if i == k:
        break
    m[i] = p
    p += 1
    i = l[i]
else:
    z = (k - m[i]) % (p - m[i])
    i = m.index(m[i] + z)
print(i + 1)