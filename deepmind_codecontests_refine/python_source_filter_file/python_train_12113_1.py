x = list(map(int, input().split()))
t = x[1]
flag = 0
a, b, = [], []
while x[2] > 0 and x[1] > 0:
    a.append(x[2])
    x[2] -= x[4]
    x[1] -= 1
while x[3] > 0 and t > 0:
    b.append(x[3])
    x[3] -= x[5]
    t -= 1
for i in range(len(a)):
    for j in range(len(b)):
        if a[i] + b[j] == x[0]:
            print('YES')
            flag = 1
            break
        if i == len(a) - 1 and j == len(b) - 1:
            print('NO')
    if flag == 1:
        break
