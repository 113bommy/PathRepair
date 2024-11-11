from collections import deque

class Dinic():
    def __init__(self, listEdge, s, t):
        self.s = s
        self.t = t
        self.graph    = {}
        self.maxCap   = 1000000
        # dict các node lân cận
       
        # e[0]: from,  e[1]: to,  e[2]: dung luong  
        for e in listEdge:
            
            if e[0] not in self.graph:
                self.graph[e[0]] = []
             
            if e[1] not in self.graph:
                self.graph[e[1]] = []
                                   #to     #cap   #reveser edge
            self.graph[e[0]].append([e[1], e[2],  len(self.graph[e[1]])])
            self.graph[e[1]].append([e[0],    0,  len(self.graph[e[0]])-1])
            
        self.N = len(self.graph.keys())
    
    def bfs(self):
        self.dist    = {}
        self.dist[self.s] = 0
        self.curIter = {node:[] for node in self.graph}
        
        Q = deque([self.s])
        
        while(len(Q) > 0):
            cur = Q.popleft()
            
            for index,e in enumerate(self.graph[cur]):
                # Chỉ add vào các node kế tiếp nếu dung lượng cạnh > 0 và chưa được visit trước đấy 
                if e[1] > 0 and e[0] not in self.dist:
                    self.dist[e[0]] = self.dist[cur] + 1
                    # add vào danh sách node kế tiếp của node hiện tại
                    self.curIter[cur].append(index)
                    Q.append(e[0])
        
        
    def findPath(self, cur, f):
        if cur == self.t:
            return f
        
        while len(self.curIter[cur]) > 0:
            indexEdge    = self.curIter[cur][-1]
            nextNode     = self.graph[cur][indexEdge][0]
            remainCap    = self.graph[cur][indexEdge][1]
            indexPreEdge = self.graph[cur][indexEdge][2]
            
            if remainCap > 0 and self.dist[nextNode] > self.dist[cur]:
                #self.next[cur] = indexEdge
                flow = self.findPath(nextNode,  min(f, remainCap))
                
                if flow > 0:
                    self.path.append(cur)
                    self.graph[cur][indexEdge][1]            -= flow
                    self.graph[nextNode][indexPreEdge][1]    += flow
                    #if cur == self.s:
                    #    print(self.path, flow)
                    return flow 
                #else:
                    #self.path.pop()
            self.curIter[cur].pop() 
            
        return 0
    
    def maxFlow(self):
        maxflow = 0
        flow = []
        
        while(True):
            self.bfs()
            
            if self.t not in self.dist:
                break
                
            while(True):
                self.path    = []
                f = self.findPath(self.s, self.maxCap)
                #print('iter', self.curIter)
                if f == 0:
                    break
                    
                flow.append(f)    
                maxflow += f
            
        return maxflow    

    # Tìm tập node thuộc S và T
    # sau khi đã tìm được max flow
    def residualBfs(self):
        Q = deque([self.s])
        side = {self.s:'s'}
        
        while(len(Q) > 0):
            cur = Q.popleft()
            
            for index,e in enumerate(self.graph[cur]):
                if e[1] > 0 and e[0] not in side:
                    Q.append(e[0])
                    side[e[0]] = 's'
        
        S = []
        T = [] 
        for x in self.graph:
            if x in side:
                S.append(x)
            else:
                T.append(x)
        return set(S), set(T)
        
def push(G, u, v):
    if u not in G:
        G[u]=[]
    if v not in G:
        G[v]=[]
    G[u].append(v)
    G[v].append(u)
    
def bfs(u, used, G):
    l, r   = G[u][0], G[u][1] 
    used[u]=1
    used[l]=1
    used[r]=1
    
    S=[l,u,r]
    i=2
    while i < len(S):
        cur=S[i]
        if cur in G:
            for v in G[cur]:
                if used[v]==0:
                    used[v]=1
                    S.append(v)
        i+=1
    return S   

max_  = 20001
prime = [1] * max_

for i in range(2, max_):
    if prime[i] == 1:
        for j in range(2*i, max_, i):
            prime[j] = 0

n  = int(input())
a  = list(map(int, input().split()))

diff = 0
for x in a:
    if x%2==0:
        diff+=1
    else:
        diff-=1

flg=True
if diff != 0:
    flg=False
else:
    edge = []
    for i in range(n):
        if a[i]%2==1:
            edge.append([i,'t', 2])
            continue
        
        edge.append(['s', i, 2])    
        for j in range(n):
            if a[j]%2==1 and prime[a[i]+a[j]] == 1:
                edge.append([i, j, 1])
                
    g = Dinic(edge, 's', 't')
    F = g.maxFlow()
            
    if F != n:
        flg=False
    else:
        G = {}

        for u, es in g.graph.items():
            if u in ['s', 't'] or a[u] % 2 == 1:
                continue
        
            for e in es:
                v, remain = e[0], e[1]
                if isinstance(v, int) == True and remain == 0:
                    push(G, u, v)  
    
        used = [0]*n
        comp = []
        for i in range(0, n, 2):
            if a[i]%2==0 and used[i]==0:
                comp.append(bfs(i, used, G))
                
if flg==False:
    print('Impossible')
else:
    print(len(comp))
    for nodes in comp:
        for i in range(len(nodes)):
            nodes[i] += 1
        arr = [len(nodes)] + nodes
        print(' '.join([str(x) for x in arr]))                