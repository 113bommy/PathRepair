s = input()
L = len(s)
r = 0
def check(s, b, l):
    t = 0
    for i in range(l):
        ok = 0
        for j in range(t, L):
            if b[i] == s[j]:
                t = j + 1
                ok = 1
                break
        if not ok:
            return 0
    return 1
for i in range(1, int(int(s) ** 0.5) + 2):
    b = str(i * i)
    l = len(b)
    if check(s, b, l):
        r = max(l, r)
print(L - r if r else -1)
