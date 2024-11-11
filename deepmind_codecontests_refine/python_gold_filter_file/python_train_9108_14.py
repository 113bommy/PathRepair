t = int(input())
a = list()
for _ in range(t):
    a.append(list(map(int, input().split())))
a.sort()
if t == 1:
    print("-1")
elif t == 2:
    if a[1][1] == a[0][1] or a[0][0] == a[1][0]:
        print("-1")
    else:
        print(abs(a[1][0] - a[0][0])*abs(a[1][1] - a[0][1]))
elif t == 3:
    if a[0][0] == a[1][0]:
        print((a[2][0] - a[0][0])*(a[1][1] - a[0][1]))
    else:
        print((a[1][0] - a[0][0])*(a[2][1] - a[1][1]))
else:
    print((a[3][0] - a[0][0])*(a[3][1] - a[0][1]))