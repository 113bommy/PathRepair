N = int(input())
L = list(map(int, input().split(' ')))

def isPrime(x) :
    for i in range(2, int(x**0.5)+2) :
        if x % i == 0 : return False
    return True

odd = []
even = []
for i in range(N) :
    if L[i]%2 == 0 :
        even.append(i)
    else :
        odd.append(i)

if len(odd) != len(even) :
    print("Impossible")
    exit()

cap = [[0]*(N+2) for i in range(N+2)]
for i in odd :
    cap[N][i] = 2
for i in even :
    cap[i][N+1] = 2
for i in odd :
    for j in even :
        if isPrime(L[i]+L[j]) :
            cap[i][j] = 1

def send(x, flow) :
    global visited, N
    if x == N+1 or flow == 0: return flow
    visited[x] = True
    ret = 0
    for nxt in range(N+2) :
        if visited[nxt] : continue
        if cap[x][nxt] == 0 : continue
        n_flow = min(cap[x][nxt], flow)
        n_flow = send(nxt, n_flow)
        flow -= n_flow
        ret += n_flow
        cap[x][nxt] -= n_flow
        cap[nxt][x] += n_flow
    return ret

flow = 0
while True :
    visited = [False]*(N+2)
    f = send(N, N)
    if f == 0 : break
    flow += f

if flow != N :
    print("Impossibl")
    exit()

def dfs(x, path) :
    global visited, N, edge
    visited[x] = True
    ret = 1
    path.append(x)
    for nxt in edge[x] :
        if visited[nxt] : continue
        ret += dfs(nxt, path)
    return ret

visited = [False]*N
edge = [[] for i in range(N)]
for i in odd :
    for j in even :
        if cap[j][i] == 1 :
            edge[i].append(j)
            edge[j].append(i)
cnt = []
ans = []
for i in range(N) :
    if visited[i] == True : continue
    ans.append([])
    cnt.append(dfs(i, ans[-1]))

print(len(cnt))
for i in range(len(cnt)) :
    print(cnt[i], end = ' ')
    for j in ans[i] :
        print(j+1, end = ' ')
    print()