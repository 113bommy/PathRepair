n = int(input())
d = []
for i in range(n):
    xx, ww = [int(i) for i in input().split()]
    d.append([xx-ww, xx+ww])
d.sort(key=lambda x:x[0])
last = -10000000
ans = 0
for i in range(n):
    if last <= d[i][0]:
        last = d[i][1]
        ans += 1
    elif last > d[i][1]:
        last = d[i][1]
print(ans)





