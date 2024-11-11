n = int(input())
p = list(map(int,input().split()))
ps = set(p)
s = list(map(int,input().split()))
ok = True
for i in range(1, n + 1):
    if not i in ps:
        if s[i - 1] == -1:
            m = s[p[i - 2] - 1]
        else:
            m = s[i - 1]
        j = i
        while j != 1:
            if m < s[j - 1]:
                ok = False
                break
            if s[j - 1] != -1:
                m = s[j - 1]
            j = p[j - 2]
        if m < s[0]:
            ok = False
    if not ok:
        break
if ok:
    sp = [-1] * n
    for i in range(n - 1):
        if sp[p[i] - 1] == -1:
            sp[p[i] - 1] = [i + 2]
        else:
            sp[p[i] - 1].append(i + 2)
    a = [0] * n
    a[0] = s[0]
    for i in range(1, n + 1):
        if s[i - 1] == -1 and sp[i - 1] != -1:
            m = sp[i - 1][0] - s[p[i - 2] - 1]
            for j in sp[i - 1]:
                m = min(m, s[j - 1] - s[p[i - 2] - 1])
            a[i - 1] = m
    for i in range(2, n + 1):
        if s[i - 1] != -1:
            a[i - 1] = s[i - 1] - s[p[p[i - 2] - 2] - 1] - a[p[i - 2] - 1]
    print(sum(a))
else:
    print(-1)