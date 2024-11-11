x, y = map(int, input().split())
f = list(map(int, input().split()))
l = list(map(int, input().split()))
c = []
i = 10
j = 10
for num in f:
    i = min(i, num)
for num in l:
    j = min(j, num)
for k in f:
    for m in l:
        if k == m:
            c.append(k)
if len(c) > 0:
    print(min(c))
elif i == j:
    print(i)
else:
    one = int(str(i)+str(j))
    sec = int(str(j)+str(i))
    print(min(one, sec))