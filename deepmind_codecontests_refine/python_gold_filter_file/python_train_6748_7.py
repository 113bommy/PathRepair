from collections import defaultdict
N, M = map( int, input().split())
S = list( input())
E = [ list( map( int, input().split())) for _ in range(M)]
V = [ 1 for _ in range(N)]
Edges = [[] for _ in range(N)]
A = [0]*N
B = [0]*N
d = defaultdict(int)
for i in range(M):
    a, b = E[i]
    a, b = a-1, b-1
    a, b = min(a,b), max(a,b)
    Edges[a].append(b)
    Edges[b].append(a)
    if d[(a,b)] == 1:
        continue
    else:
        d[(a,b)] += 1
    if a == b:
        if S[a] == 'A':
            A[a] += 1
        else:
            B[a] += 1
        continue
    if S[a] == 'A':
        A[b] += 1
    else:
        B[b] += 1
    if S[b] == 'B':
        B[a] += 1
    else:
        A[a] += 1
T = set([])

for i in range(N):
    if A[i] == 0 or B[i] == 0:
        T.add(i)
while T:
    n = T.pop()
    V[n] = 0
    for m in set(Edges[n]):
        if V[m] == 1:
            if S[n] == 'A':
                A[m] -= 1
                if A[m] == 0:
                    T.add(m)
            else:
                B[m] -= 1
                if B[m] == 0:
                    T.add(m)
                
if sum(V) == 0:
    print('No')
else:
    print('Yes')