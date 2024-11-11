n, m = [int(i) for i in input().split()]

f = [int(i) for i in input().split()]
s = [int(i) for i in input().split()]
min = 100

for i in range(n):
    for j in range(m):
        if f[i]*10 + s[j] < min: min = f[i]*10 + s[j]
        elif s[j]*10 + f[i] < min: min = s[j]*10 + f[i]

for i in range(m):
    if s[i] in f and s[i] < min: min = s[i]

print(min)
