n = list(map(int,input().split()))
ot = (n[0] // n[2]) * n[1]
o1 = n[1]
o2 = n[3]
p = n[0] - n[2]
for i in range(n[0]):
    if (p >= n[2]):
        if (o2 > o1):
            o1 += n[1]
            p -= n[2]
        else:
            o1 += n[1]
            o2 += n[1]
            p -= (n[2]+n[2])
    elif ((p < n[2]) & (p != 0)):
        t = (p * n[1]) // n[2]
        o1 += t
        o2 += t
        p = 0
if ((o2 < ot)&(o2 != n[3])):
    print("YES")
else:
    print("NO")