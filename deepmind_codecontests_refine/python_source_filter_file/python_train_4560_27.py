n , k = map(int,input().split())
a = list(map(int,input().split()))
f = list(map(int,input().split()))
a.sort()
f.sort(reverse=True)
lef = -1
rig = 10*13

while rig - lef != 1:
    now = (rig + lef) //2
    cou = 0
    for i in range(n):
        t = now // f[i]
        cou += max(0,a[i]-t)
    if cou <= k:
        rig = now
    elif cou > k:
        lef = now
print(rig)