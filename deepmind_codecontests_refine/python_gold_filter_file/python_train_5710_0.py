import sys
input = sys.stdin.readline

MOD = 10**9 + 7

N = int(input())
ball = [tuple(int(x) for x in input().split()) for _ in range(N+N)]

# x座標を1,2,...,N
# y座標をN+1,N+2,...,N+N

graph = [set() for _ in range(N+N+1)]
for x,y in ball:
    graph[x].add(y+N)
    graph[y+N].add(x)

visited = set()
components = []
for x in range(1,N+N+1):
    if x in visited:
        continue
    V = set([x])
    q = [x]
    while q:
        y = q.pop()
        for z in graph[y]:
            if z in V:
                continue
            V.add(z)
            q.append(z)
    visited |= V
    components.append(V)

def make_get_patterns(V):
    deg1 = [x for x in V if len(graph[x]) == 1]
    get = {},{}
    while deg1:
        x = deg1.pop()
        if not graph[x]:
            continue
        y = graph[x].pop()
        se = graph[y]; se.remove(x)
        if len(se) == 1: deg1.append(y)
        if x < y:
            get[0][(x,y)] = 0; get[1][(x,y)] = 0
        else:
            pass
            get[0][(y,x)] = 1; get[1][(y,x)] = 1
    for x in V:
        if graph[x]:
            y = graph[x].pop()
            break
    # 残りはサイクル
    graph[y].remove(x)
    if x > y: x,y = y,x
    get[0][(x,y)] = 0; get[1][(x,y)] = 1
    while True:
        if not graph[x]:
            break
        y = graph[x].pop()
        graph[y].remove(x)
        if x < y:
            get[0][(x,y)] = 1; get[1][(x,y)] = 0
        else:
            get[0][(y,x)] = 0; get[1][(y,x)] = 1
        x = y
    return get

def F(V):
    # V is connected
    E = sorted((x,y) for x in V if x <= N for y in graph[x])
    if len(E) != len(V):
        return 0
    ret = 0
    for get in make_get_patterns(V):
        den = 1
        dp = {x:0 for x in V}
        for x,y in E:
            if get[(x,y)] == 0:
                k = dp[x] + 1
            else:
                k = dp[y] + 1
            dp[x] += k
            dp[y] += k
            den *= k
            den %= MOD
        ret += pow(den,MOD-2,MOD)
    return ret % MOD

prob = 1
for c in components:
    prob *= F(c)
    prob %= MOD

answer = prob
for n in range(1,N+N+1):
    answer *= n
    answer %= MOD
print(answer)
