n = int(input())
s = list(str(input()))

c0, c1, c2 = 0, 0, 0
C0 = []
C1 = []
C2 = []
for i in range(n):
    if s[i] == '0':
        c0 += 1
        C0.append(i)
    elif s[i] == '1':
        c1 += 1
        C1.append(i)
    else:
        c2 += 1
        C2.append(i)

import copy
if c0 > n//3:
    if c1 > n//3:
        ans = copy.copy(s)
        for i in range(n//3, c0):
            j = C0[i]
            ans[j] = '2'
        for i in range(n//3, c1):
            j = C1[i]
            ans[j] = '2'
    elif c2 > n//3:
        ans = copy.copy(s)
        for i in range(n//3, c0):
            j = C0[i]
            ans[j] = '1'
        for i in range(n//3-c2):
            j = C2[i]
            ans[j] = '1'
    else:
        ans = copy.copy(s)
        temp = ['1']*(n//3-c1)+['2']*(n//3-c2)
        for i in range(n//3, c0):
            j = C0[i]
            ans[j] = temp[i-n//3]
elif c1 > n//3:
    if c2 > n//3:
        ans = copy.copy(s)
        for i in range(c1-n//3):
            j = C1[i]
            ans[j] = '0'
        for i in range(c2-n//3):
            j = C2[i]
            ans[j] = '0'
    else:
        ans = copy.copy(s)
        for i in range(n//3-c0):
            j = C1[i]
            ans[j] = '0'
        for i in range(c1-(n//3-c2), c1):
            j = C1[i]
            ans[j] = '2'
elif c2 > n//3:
    ans = copy.copy(s)
    temp = ['0']*(n//3-c0)+['1']*(n//3-c1)
    for i in range(c2-n//3):
        j = C2[i]
        ans[j] = temp[i]
else:
    ans = copy.copy(s)
print(''.join(ans))
