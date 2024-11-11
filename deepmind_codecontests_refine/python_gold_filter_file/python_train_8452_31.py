n = int(input())
a = list(list(map(int, input().split())) for i in range(n))
for i in range(n):
    s = ""
    p = abs(a[i][3] - a[i][2]) + a[i][1]
    if p >= a[i][0]:
        s += str(str(a[i][0]-1) + " ")
    else:
        s += str(str(p) + " ")
    print(s)