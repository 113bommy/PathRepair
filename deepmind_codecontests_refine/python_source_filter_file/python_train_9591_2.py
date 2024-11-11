a = input().split()
b = int(a[1])
a = int(a[0])
c = input().split()
ans = 0
for i in range(a):
    gg = c[:]
    e = 0
    s = 0
    for x in range(i,a,b):
        gg[x] = 0
    for i in gg:
        if i == "-1":
            s+=1
        if i == "1":
            e+=1
    ttt = e - s
    if ttt < 0:
        ttt *= -1
    if ans < ttt:
        ans = ttt
print(ans)