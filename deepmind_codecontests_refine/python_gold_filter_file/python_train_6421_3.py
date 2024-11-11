n, m = map(int, input().split())
a = list(map(int, input().split()))
for q in range(0, len(a), 2):
    a[q//2] = [a[q], a[q+1]]
s = list(map(int, input().split()))
for q in range(0, len(s), 2):
    s[q//2] = [s[q], s[q+1]]
a, s = a[:n], s[:m]
may = [0]*10
for q in a:
    may1 = [0]*10
    for q1 in s:
        if q[0] == q1[0] and q[1] != q1[1]:
            may[q[0]] = 1
            may1[q[0]] = 1
        if q[0] == q1[1] and q[1] != q1[0]:
            may[q[0]] = 1
            may1[q[0]] = 1
        if q[1] == q1[0] and q[0] != q1[1]:
            may[q[1]] = 1
            may1[q[1]] = 1
        if q[1] == q1[1] and q[0] != q1[0]:
            may[q[1]] = 1
            may1[q[1]] = 1
    if may1.count(1) == 2:
        print(-1)
        break
else:
    for q in s:
        may1 = [0]*10
        for q1 in a:
            if q[0] == q1[0] and q[1] != q1[1]:
                may[q[0]] = 1
                may1[q[0]] = 1
            if q[0] == q1[1] and q[1] != q1[0]:
                may[q[0]] = 1
                may1[q[0]] = 1
            if q[1] == q1[0] and q[0] != q1[1]:
                may[q[1]] = 1
                may1[q[1]] = 1
            if q[1] == q1[1] and q[0] != q1[0]:
                may[q[1]] = 1
                may1[q[1]] = 1
        if may1.count(1) == 2:
            print(-1)
            break
    else:
        if may.count(1) == 1:
            print(may.index(1))
        else:
            print(0)
