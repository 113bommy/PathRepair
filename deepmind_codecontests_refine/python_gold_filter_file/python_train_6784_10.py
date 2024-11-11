a = input()
b = input()
n = len(a)
m = len(b)

def change(a):
    pref = [0] * (len(a))
    for i in range(1, len(a)):
        pref[i] = pref[i - 1] + (a[i] != a[i - 1])
    return pref

equals = 0
pref = change(a)
for i in range(m):
    equals += (a[i] != b[i])
parity = equals % 2
f = int(not parity)
for i in range(m, n):
    parity += (pref[i] - pref[i - m]) % 2
    f += (parity % 2 == 0)
print(f)