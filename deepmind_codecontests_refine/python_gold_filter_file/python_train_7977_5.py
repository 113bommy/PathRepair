n = int(input())

d = {}
dic = {}
for i in range(1, n):
    x = int(input())
    if not x in d:
        d[x] = []
    d[x].append(i + 1)
    dic[i + 1] = x
    if x > 1:
        if x in d[dic[x]]:
            d[dic[x]].remove(x)

flag = True
for x in d:
    if len(d[x]) < 3:
        flag = False
        break

if flag:
    print("Yes")
else:
    print("No")
