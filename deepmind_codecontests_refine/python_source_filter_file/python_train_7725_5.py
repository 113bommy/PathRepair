import bisect
n = int(input())
x = []
y = []
asc = 0
ans = 0
temp_s = [list(map(int,input().split())) for i in range(n)]
for i in range(n):
    xm = 200000
    yM = 0
    f_asc = 0
    for j in temp_s[i][1:]:
        if j > yM:
            yM = j
        if j < xm:
            xm = j
        if j > xm:
            f_asc = 1
    if f_asc == 0:
        x.append(xm)
        y.append(yM)
    else:
        asc += 1

y.sort()
x.sort()

ans += (asc*(2*len(y) + asc))
for i in y:
    ans += bisect.bisect_left(x,i)
# print(x)
# print(y)
# print(asc)
print(ans)