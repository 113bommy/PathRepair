from collections import deque

def R():
    return map(int, input().strip().split())

n, m = R()
graph = {}
for i in range(m):
    u, v = R()
    try:
        graph[u].append(v)
    except:
        graph[u] = [v]
    try:
        graph[v].append(u)
    except:
        graph[v] = [u]

try:
    dp = [1 for i in range(n+1)]
    for i in range(1, n+1):
        for j in graph.get(i, []):
            if j > i:
                dp[j] = max(dp[j], dp[i]+1)


    ans = 0
    # print(dp)
    for i in graph:
        ans = max(len(graph[i])*dp[i], ans)
    print(ans)
except Exception as e:
    print(e)



                    
    
    




