s = input()
n = len(s)
k = 1
p = 1
for i in range(n - 1):
    if (int(s[i]) + int(s[i + 1])) % 9 == 0 and s[i] != '9' and s[i] != '0':
        k += 1
    else:
        if k > 1 and k % 2 == 1:
            p *= (k + 1) // 2
            k = 1
if k > 1 and k % 2 == 1:
    p *= (k + 1) // 2
print(p)
