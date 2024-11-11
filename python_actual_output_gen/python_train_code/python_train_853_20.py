n = int(input())
s = [int(i) for i in list(input())]
s1 = sorted(s[:n])
s2 = sorted(s[n:])
b = False
for i in range(n):
    if i == 0:
        if s1[i] > s2[i]:
            a = True
        elif s1[i] < s2[i]:
            a = False
        else:
            b = True
            break
    if a:
        if s1[i] < s2[i]:
            b = True
            break
    else:
        if s1[i] > s2[i]:
            b = True
            break
if b:
    print('NO')
else:
    print('YES')