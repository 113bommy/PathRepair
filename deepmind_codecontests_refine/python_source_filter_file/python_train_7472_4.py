
n = int(input())
s = [list(input()) for i in range(n)]
r = []
l = []
ans = 0
for i in s:
    now = 0
    c = 0
    for j in i:
        if j =="(":
            now += 1
        else:
            now -= 1
        c = min(c,now)
    if c == 0:
        ans += now
    elif now >= 0:
        l.append([c,now])
    else:
        r.append([c,-now])

l.sort(reverse =True)
r.sort()
for i,j in l:
    if ans + i < 0:
        print("No")
        exit()
    else:
        ans += j

for i,j in r:
    if ans+i < 0:
        print("No")
        exit()
    else:
        ans -= j
if ans == 0:
    print("Yes")
else:
    print("No")
