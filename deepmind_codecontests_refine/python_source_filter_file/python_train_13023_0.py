from random import randint

values = [[] for _ in range(10)]
types = [[0, 1, 2, 3], [1, 4, 5, 6], [2, 5, 7, 8], [3, 6, 8, 9]]
b = [1]*10
B = 128
for i in range(9):
    b[i+1] = b[i]*B

for i in range(4):
    values[types[i][i]].append(0)

n = int(input())
for _ in range(n):
    i, v, j = map(int,input().split())
    t = types[i-1][j-1]
    if i == j:
        values[t][0] += v
    else:
        values[t].append(v)


for i in range(4):
    for j in range(i+1,4):
        t = types[i][j]
        values[t].sort()
        while len(values[t])>=3:
            v=values[t].pop()+ values[t].pop()
            values[t][-1]+= v
        values[t].sort(reverse = True)

cur=[{},{},{},{}]
m = 0
for i in range(4):
    for j in range(i,4):
        t = types[i][j]
        if values[t]:
            cur[i][b[t]] = values[t][0]
            m = max(m,values[t][0])

def cnt(k,t):
    return k//b[t]%B

for _ in range(n):
    next = [{},{},{},{}]
    for i in range(4):
        for j in range(4):
            t = types[i][j]
            for k, v in cur[i].items():
                c = cnt(k,t)
                if len(values[t])>c:
                    nk = k+b[t]
                    if nk not in next[j]:
                        next[j][nk] = values[t][c] + v
                        m = max(m, values[t][c] + v)
    cur = next

print (m)