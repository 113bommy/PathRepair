n = 3
def judge(c, a):
    res = [0, 0]
    for i in range(0, n):
        if a[i][0] == a[i][1] == a[i][2] == c:
            res[0] += 1
    for i in range(0, n):
        if a[0][i] == a[1][i] == a[2][i] == c:
            res[0] += 1
    if a[0][0] == a[1][1] == a[2][2] == c:
        res[0] += 1
    if a[0][2] == a[1][2] == a[2][0]:
        res[0] += 1
    for i in range(n):
        for j in range(n):
            if a[i][j] == c:
                res[1] += 1
    return res
s = [input(), input(), input()]
t1, t2 = judge('X', s), judge('0', s)
if (t1[0] > 0 and t2[0] > 0) or t2[1] > t1[1] or t1[1] - t2[1] > 1 or (t1[0] > 0 and t2[1] >= t1[1]) or (t2[0] > 0 and t2[1] < t1[1]):
    print('illegal')
elif t1[0] > 0:
    print('the first player won')
elif t2[0] > 0:
    print('the second player won')
elif t1[1] + t2[1] == 9:
    print('draw')
elif t1[1] == t2[1]:
    print('first')
elif t1[1] - t2[1] == 1:
    print('second')

