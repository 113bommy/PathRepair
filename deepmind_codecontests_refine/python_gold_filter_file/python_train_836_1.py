from collections import deque, defaultdict

def topological_sort(V, E):
    '''
    Kahn's Algorithm (O(|V| + |E|) time)
    Input:
    V = [0, 1, ..., N-1]: a list of vertices of the digraph
    E: the adjacency list of the digraph (dict)
    Output:
    If the input digraph is acyclic, then return a topological sorting of the digraph.
    Else, return None.
    '''
    indeg = {v: 0 for v in V}
    for ends in E.values():
        for v in ends:
            indeg[v] += 1
    
    q = deque([v for v in V if indeg[v] == 0])
    top_sorted = []
    while q:
        v = q.popleft()
        top_sorted.append(v)
        
        for u in E[v]:
            indeg[u] -= 1
            if indeg[u] == 0:
                q.append(u)
    if len(top_sorted) == len(V): # The input digraph is acyclic.
        return top_sorted
    else: # There is a directed cycle in the digraph.
        return None

N, M = map(int, input().split())
V = range(N)
E = defaultdict(list)
for _ in range(M):
    s, t = map(int, input().split())
    E[s].append(t)
print(1 if topological_sort(V, E) is None else 0)
