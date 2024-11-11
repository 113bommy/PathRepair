#coding: utf-8

n = int(input())
color = ["white" for i in range(n)]
d = [[] for i in range(n)]
global t
t = 0
M = [[False for i in range(n)] for j in range(n)]
for i in range(n):
    data = list(map(int,input().split()))
    u = data[0]
    k = data[1]
    if i == 0:
        start = u
    for v in data[2:2+k]:
        M[u-1][v-1] = True


def search(u,t):
    t += 1
    color[u-1] = "gray"
    d[u-1].append(t)
    for v in range(n):
        if M[u-1][v-1] and color[v-1] == "white":
            t = search(v,t)
    color[u-1] = "black"
    t += 1
    d[u-1].append(t)
    return t

t = search(start, t)
for i in range(1,n+1):
    if color[i-1] == "white":
        t = search(i, t)

for i in range(n):
    print(i+1, d[i][0], d[i][1])

