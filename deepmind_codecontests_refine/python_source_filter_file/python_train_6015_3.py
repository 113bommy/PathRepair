from collections import deque
class csr:
    def __init__(self,N,edges):
        self.start = [0]*(N+1)
        self.elist = [0]*len(edges)
        for e in edges:
            self.start[e[0]+1] += 1
        for i in range(1,N+1):
            self.start[i] += self.start[i-1] 
        counter = self.start[:]
        for e in edges:
            self.elist[counter[e[0]]] = e[1]
            counter[e[0]] += 1

class scc_graph:
    def __init__(self,N):
        self.N = N
        self.edges = []
    
    def add_edge(self,v,w):
        self.edges.append((v,w))

    def scc_ids(self):
        g = csr(self.N,self.edges)
        now_ord = group_num = 0
        visited = deque()
        low = [0]*self.N
        order = [-1]*self.N
        ids = [0]*self.N
        parent = [-1]*self.N
        for i in range(self.N):
            if order[i] == -1:
                stack = deque()
                stack.append(i)
                stack.append(i)
                while stack:
                    v = stack.pop()
                    if order[v] == -1:
                        low[v] = order[v] = now_ord
                        now_ord += 1
                        visited.append(v)
                        for i in range(g.start[v],g.start[v+1]):
                            to = g.elist[i]
                            if order[to] == -1:
                                stack.append(to)
                                stack.append(to)
                                parent[to] = v
                            else:
                                low[v] = min(low[v],order[to])
                    else:
                        if low[v] == order[v]:
                            while True:
                                u = visited.pop()
                                order[u] = self.N
                                ids[u] = group_num
                                if u == v:
                                    break
                            group_num += 1
                        if parent[v] != -1:
                            low[parent[v]] = min(low[parent[v]],low[v])
        for i,x in enumerate(ids):
            ids[i] = group_num-1-x

        return group_num,ids
    
    def scc(self):
        group_num,ids = self.scc_ids()
        groups = [[] for _ in range(group_num)]
        for i,x in enumerate(ids):
            groups[x].append(i)
        return groups
    
import sys
readline = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
N,M = map(int,readline().split())
ab = list(map(int,read().split()))
sg = scc_graph()

it = iter(ab)
for a,b in zip(it,it):
    sg.add_edge(a,b)

scc = sg.scc()
print(len(scc))
for group in scc:
    print(*([len(group)] + group))