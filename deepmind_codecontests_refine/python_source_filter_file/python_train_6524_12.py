n, x, y = [int(i) for i in input().split()]
s = [int(i) for i in input()]
lis = []
ind = -1
flag0 = flag1 = 0
for i in range(n):
    if s[i] == 0 and flag0 == 0:
        ind = i
        flag0 = 1
        flag1 = 0
    else:
        if s[i] == 1 and flag1 == 0:
            if ind != -1:
                lis.append(ind)
            flag1 = 1
            flag0 = 0
if flag1 == 0 and flag0 == 1:
    if ind != -1:
        lis.append(ind)
x1 = len(lis)
if x1 == 0:
    print(0)
else:
    ans = (x1 - 1) * (min(x, y) + y)
    print(ans)
