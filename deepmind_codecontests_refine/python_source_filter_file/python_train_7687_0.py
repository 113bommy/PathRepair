import itertools

N, M = map(int, input().split())
E = [[] for i in range(N)]
for i in range(N):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    E[a].append(b)
    E[b].append(a)

count = 0
for V in itertools.permutations(range(1, N)):
    if V[0] in E[0] and all(V[i] in E[V[i-1]] for i in range(1, N-1)):
        count += 1
print(count)        
