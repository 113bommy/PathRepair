s = input()
t = input()
e = d = 0
for i in range(len(s)):
    if s[i] == t[i]:
        e += 1
    else:
        d += 1
if d % 2 or e % 2:
    print('impossible')
else:
    k = 0; z = d//2
    p = [0]*len(s)
    for i in range(len(s)):
        if k < z and s[i] != t[i]:
            p[i] = s[i]
            k += 1
        elif k >= z and s[i] != t[i]:
            p[i] = t[i]
            k += 1
        else:
            if s[i] == '1':
                p[i] = '0'
            else:
                p[i] = '1'
    for i in p:
        print(i, end='')
