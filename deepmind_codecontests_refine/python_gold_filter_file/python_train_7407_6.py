import collections

def do():
    n = int(input())
    res = 1
    ind = collections.defaultdict(int)
    graph = collections.defaultdict(list)
    stack = []
    for i in range(1, n+1):
        m = int(input())
        if m != -1:
            graph[m].append(i)
            ind[i] += 1
    for i in range(1, n+1):
        if ind[i] == 0:
            stack.append([i, 1])
    while stack:
        cur, l = stack.pop()
        res = max(res, l)
        for nei in graph[cur]:
            stack.append([nei, l+1])
    return res

print(do())
