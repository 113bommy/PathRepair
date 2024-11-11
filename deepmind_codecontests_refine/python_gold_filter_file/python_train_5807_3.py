from collections import deque

class mf_graph:
    def __init__(self,N):
        self.N = N
        self.graph = [[] for _ in range(N)]
    
    def add_edge(self,v,w,cap):
        edge = [w,cap,None]
        edge[2] = rev_edge = [v,0,edge]
        self.graph[v].append(edge)
        self.graph[w].append(rev_edge)
    
    def bfs(self,s,t):
        self.level = [None]*self.N
        q = deque([s])
        self.level[s] = 0
        while q:
            v = q.popleft()
            lw = self.level[v]+1
            for w,cap,_ in self.graph[v]:
                if cap and self.level[w] is None:
                    self.level[w] = lw
                    q.append(w)
        return self.level[t] is not None
    
    def dfs(self,s,t,up):
        st = deque([t])
        while st:
            v = st[-1]
            if v == s:
                st.pop()
                flow = up
                for w in st:
                    e = self.graph[w][self.it[w]][2]
                    flow = min(flow,e[1])
                for w in st:
                    e = self.graph[w][self.it[w]]
                    e[1] += flow
                    e[2][1] -= flow
                return flow
            lv = self.level[v]
            while self.it[v] < len(self.graph[v]):
                w,_,e = self.graph[v][self.it[v]]
                cap = e[1]
                if cap and self.level[w] is not None:
                    if lv > self.level[w]:
                        st.append(w)
                        break
                self.it[v] += 1
            if self.it[v] == len(self.graph[v]):
                st.pop()
                self.level[v] = self.N
        return 0
    
    def flow(self,s,t,flow_limit=float('inf')):
        flow = 0
        while flow < flow_limit and self.bfs(s,t):
            self.it = [0]*self.N
            while flow < flow_limit:
                f = self.dfs(s,t,flow_limit-flow)
                if not f:
                    break
                flow += f
        return flow

    def min_cut(self,s):
        visited = [False]*self.N
        q = deque([s])
        while q:
            v = q.pop()
            visited[v] = True
            for w,cap,_ in self.graph[v]:
                if cap and not visited[w]:
                    q.append(w)

N,M = map(int, input().split())
S = [list(input()) for i in range(N)]
dc = mf_graph(N*M+2)

s =N*M
t = N*M+1
for i in range(N):
    for j in range(M):
        if (i+j) % 2 == 0:
            dc.add_edge(s,M*i+j,1)
        else:
            dc.add_edge(M*i+j,t,1)

for i in range(N):
    for j in range(M):
        if j+1 < M and S[i][j] == "." and S[i][j+1] == ".":
            u,v = M*i+j,M*i+j+1
            if (i+j) % 2 == 1:
                u,v = v,u
            dc.add_edge(u, v, 1)
        if i+1 < N and S[i][j] == "." and S[i + 1][j] == ".":
            u,v = M*i+j, M*(i+1)+j
            if (i+j) % 2 == 1:
                u,v = v,u
            dc.add_edge(u,v,1)

print(dc.flow(s, t))
for u in range(N*M+2):
    for v, cap, _ in dc.graph[u]:
        ui, uj = divmod(u, M)
        vi, vj = divmod(v, M)
        if (ui+uj) % 2 == 0 and cap == 0 and u != s and u != t and v != s and v!= t:
            if ui+1 == vi:
                S[ui][uj] = "v"
                S[vi][vj] = "^"
            elif ui == vi+1:
                S[ui][uj] = "^"
                S[vi][vj] = "v"
            elif uj+1 == vj:
                S[ui][uj] = ">"
                S[vi][vj] = "<"
            elif uj == vj+1:
                S[ui][uj] = "<"
                S[vi][vj] = ">"

for res in S:
    print("".join(res))
