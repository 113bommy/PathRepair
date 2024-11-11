n = int(input()) + 1
t = [0] + list(map(int, input().split()))

s = [0] * n
for j in t: s[j] += 1

p = [0] * n
k = 1

for i, j in enumerate(t):
    if s[j] > 1:
        while s[k]: k += 1
        if j > k or p[j]:
            t[i] = k
            s[j] -= 1
            k += 1
        else:
            p[j] = 1

print(s.count(0))
print(' '.join(map(str, t[1:])))