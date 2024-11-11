n = int(input())
l = list(map(int,input().split()))

v = []
if l[0] == 2:
    fl = True
else:
    fl = False

s = 1

for i in range(1,n):
    if l[i] == l[i-1]:
        s += 1
    else:
        if fl:
            v.append(s)
        else:
            v.append(-s)

        s = 1
        fl = not fl

if fl:
    v.append(s)
else:
    v.append(-s)

smax = 0

for i in range(len(v)):
    if v[i] < 0:
        if i + 1 < n and v[i+1] > 0:
            smax = max(smax,min(-v[i],v[i+1]))
        elif i - 1 >= 0 and v[i-1] > 0:
            smax = max(smax,min(-v[i],v[i-1]))

print(smax*2)
