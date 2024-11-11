n = int(input())
m = []
for i in range(0, n):
    a, b = map(int, input().split())
    m.append((a, b))
m.sort()
a1 = -1
a2 = -1
flag = 'YES'
for i in range(n):
    if m[i][0] > a1:
        a1 = m[i][1]
    elif m[i][1] > a2:
        a2 = m[i][1]
    else:
        flag = 'NO'
print(flag)