n = int(input())
e = []
for i in range(n):
    x = int(input())
    if x == 1:
        e.append(0)
    else:
        e.append(x // 2 - 1)
for i in e:
    print(i)

