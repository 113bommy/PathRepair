from collections import deque

N,M = map(int,input().split())

data = [[] for _ in range(3*N)]

for i in range(M):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    data[3*u].append(3*v+1)
    data[3*u+1].append(3*v+2)
    data[3*u+2].append(3*v)

S,T = map(int,input().split())
S -= 1
T -= 1

inf = 10**6
stack = deque([[3*S,0]])
time = [inf] * (3*N)

while stack:
    x = stack.pop()
    for y in data[x[0]]:
        if time[y] > x[1] + 1:
            time[y] = x[1] + 1
            stack.append([y,x[1] + 1])

if time[3*T] == inf:
    print(-1)
else:
    print(time[3*T]//3)