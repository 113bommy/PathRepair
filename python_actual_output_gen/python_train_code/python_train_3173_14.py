n = int(input())
x = []
s = 3
b = 7
f = 0
for i in range(n):
    x.append(int(input()))
for i in range(n):
    f = 0
    for j in range(x[i] // 2):
        for k in range(x[i] // 2):
            #print(j, k, s * j + b * k)
            if s * j + b * k == x[i]:
                f = 1
                print('YES')
                break
        if f == 1:
            break
    if f == 0:
        print('NO')