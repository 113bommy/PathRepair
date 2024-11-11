import sys
readline = sys.stdin.readline
N, M = map(int, readline().split())

def check(Edge, Dim):
    N = len(Edge)
    if any(d&1 for d in Dim):
        return 'No'
    if max(Dim) > 4:
        return 'Yes'
    dc4 = Dim.count(4)
    if dc4 <= 1:
        return 'No'
    if dc4 >= 3:
        return 'Yes'
    a = Dim.index(4)
    st = (a+1)%N
    used = set([a, st])
    stack = [st]
    while stack:
        vn = stack.pop()
        for vf in Edge[vn]:
            if vf not in used:
                stack.append(vf)
                used.add(vf)
    if len(used) == N:
        return 'No'
    return 'Yes'
Edge = [[] for _ in range(N)]
Dim = [0]*N

for _ in range(M):
    a, b = map(int, readline().split())
    a -= 1
    b -= 1
    Edge[a].append(b)
    Edge[b].append(a)
    Dim[a] += 1
    Dim[b] += 1

print(check(Edge, Dim))