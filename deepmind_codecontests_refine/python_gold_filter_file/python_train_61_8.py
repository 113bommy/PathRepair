p = str(input())
n = int(input())
l = []
result = 0
for i in range(n):
    l.append(str(input()))
if p in l:
    result = 1
else:
    for i in range(n):
        for j in range(i,n):
            x = l[i]
            y = l[j]
            w = x+y
            if w[1:3] == p:
                result = 1
                break
            w = y + x
            #print((w[1:3], p))
            if w[1:3] == p:
                result = 1
                break
        if result == 1:
            break
if result == 1:
    print('YES')
else:
    print('NO')