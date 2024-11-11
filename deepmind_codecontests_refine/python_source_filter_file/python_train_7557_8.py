good = list(input())
s = list(input())
stin = '*' in s
if stin:
    stind = s.index('*')
    s.pop(stind)
n = len(s)
for p in range(int(input())):
    a = list(input())
    ans = True
    if stin:
        while stind < len(a) and a[stind] not in good:
            a.pop(stind)
    if len(a) != n:
        ans = False
    else:
        for i in range(n):
            if a[i] == s[i] or a[i] in good and s[i] == '?':
                None
            else:
                ans = False
                break
    if ans:
        print('YES')
    else:
        print('NO')