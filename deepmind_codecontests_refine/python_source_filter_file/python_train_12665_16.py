n, m = (int(i) for i in input().split())
result = [[0 for i in range(n)] for j in range(n)]
p = []
for i in range(n):
    p += [input()]

for i in range(n):
    for j in range(n-m):
        flag = True
        for k in range(m):
            if p[i][j+k] == '#':
                flag = False
        if flag:
            for k in range(m):
                result[i][j+k] += 1


for i in range(n):
    for j in range(n-m):
        flag = True
        for k in range(m):
            if p[j+k][i] == '#':
                flag = False
        if flag:
            for k in range(m):
                result[j+k][i] += 1


max_p = -1
res = [-1,-1]

for i in range(n):
    for j in range(n):
        if result[i][j] > max_p:
            max_p = result[i][j]
            res[0] = i+1
            res[1] = j+1
print(*res)
