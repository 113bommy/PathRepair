a = input()
d = 0
e = 0
f = []
for i in range(len(a)):
    if a[i] == 'Q':
        f.append(d)
        for j in range(len(f)):
            e += f[-1] - f[j]
    elif a[i] == 'A':
        d += 1
print(f)
print(e)