import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)


def solve():
    A = []
    for n in range(N):
        L = len(graph[n])
        if L % 2 != 0:
            return False
        if L > 2:
            A.append(n)

    for a in A:
        if len(graph[a]) > 4:
            return True
    if len(A) < 2:
        return False
    if len(A) > 2:
        return True
    
    s, t = A
    count = 0
    for sp in graph[s]:
        pre = s
        now = sp
        while now != t:
            for np in graph[now]:
                if np != pre:
                    pre = now
                    now = np
                    break
            if now == s:
                count += 1
                break
    return count < 4

print("Yes" if solve() else "No")