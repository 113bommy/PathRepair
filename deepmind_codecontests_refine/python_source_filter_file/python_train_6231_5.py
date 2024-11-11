N,M = [int(s) for s in input().split()]
dist = [-10**9]*N
E = []
flag = 0
change = 0
N_flag = 0
for i in range(M):
    a,b,c = [int(s) for s in input().split()]
    E.append((a,b,c))
dist[0] = 0
for i in range(N):
    for (a,b,c) in E:
        if a == N or b == N:
            N_flag = 1
        newLen = dist[a-1] + c
        if newLen > dist[b-1]:
            change = 1
            dist[b-1] = newLen
            if i == N-1 and change == 1 and N_flag == 1:
                flag = 1
        change = 0
        N_flag = 0
if flag == 1:
    print('inf')
else:
    print(dist[N-1])