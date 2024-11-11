s = input()
amm_of_s = len(s)
for m in range(1, min(amm_of_s, 5) + 1):
    if (amm_of_s + m - 1) // m <= 15:
        break
a = m
b = amm_of_s // a + (amm_of_s % a != 0)
stars = a * b - amm_of_s
full = stars // m
partly = stars % m
out = ['*' * full] * m
b -= full + 1
for i in range(partly):
    out[i] += '*'
for i in range(partly):
    out[i] += s[:b]
    s = s[b:]
for i in range(partly, m):
    out[i] += s[:b + 1]
    s = s[b + 1:]
    
print(m, b + full + 1)
print('\n'.join(out))