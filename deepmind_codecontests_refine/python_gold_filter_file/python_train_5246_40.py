n = int(input())
s = input()
R = []
L = []
for i in range(n):
    if s[i] == 'R':
        R.append(i)
    elif s[i] == 'L':
        L.append(i)

if len(L) == 0:
    L.append(100000)
if len(R) == 0:
    R.append(100000)

if R[0] < L[0]:
    l = R[0] + 1
    r = R[-1] + 1
    if L[0] >= 10000:
        r += 1
    print("%d %d" % (l, r))
else:
    l = L[0] + 1
    r = L[-1] + 1
    if R[0] >= 10000:
        l -= 1
    print("%d %d" % (r, l))