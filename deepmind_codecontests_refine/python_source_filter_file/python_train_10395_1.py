class FordFulkerson:
    """max-flow-min-cut
    O(F|E|)
    """

    def __init__(self,V:int):
        """
        Arguments:
            V:num of vertex
            adj:adjedscent list(adj[from]=(to,capacity,id))
        """
        self.V = V
        self.adj=[[] for _ in range(V)]
        self.used=[False]*V

    def add_edge(self,fro:int,to:int,cap:int):
        """
        Arguments:
            fro:from
            to: to
            cap: capacity of the edge
            f: max flow value
        """
        #edge
        self.adj[fro].append([to,cap,len(self.adj[to])])
        #rev edge
        self.adj[to].append([fro,0,len(self.adj[fro])-1])

    def dfs(self,v,t,f):
        """
        search increasing path
        """
        if v==t:
            return f
        self.used[v]=True
        for i in range(len(self.adj[v])):
            (nex_id,nex_cap,nex_rev) = self.adj[v][i]
            if not self.used[nex_id] and nex_cap>0:
                d = self.dfs(nex_id,t,min(f,nex_cap))
                if d>0:
                    #decrease capacity to denote use it with d flow
                    self.adj[v][i][1]-=d
                    self.adj[nex_id][nex_rev][1]+=d
                    return d
        return 0

    def max_flow(self,s:int,t:int):
        """calculate maxflow from s to t
        """
        flow=0
        self.used = [False]*self.V
        #while no increasing path is found
        while True:
            self.used = [False]*self.V
            f = self.dfs(s,t,float("inf"))
            if f==0:
                return flow
            else:
                flow+=f


H,W = map(int,input().split())
grid=[[v for v in input()] for _ in range(H)]

F = FordFulkerson(H+W+2)
for i in range(H):
    for j in range(W):
        if grid[i][j]=="S":
            sy,sx = i,j
            F.add_edge(0,i+1,float("inf"))
            F.add_edge(0,H+j+1,float("inf"))
        elif grid[i][j]=="T":
            gy,gx=i,j
            F.add_edge(i+1,H+W+1,float("inf"))
            F.add_edge(H+j+1,H+W+1,float("inf"))
        elif grid[i][j]=="o":
            F.add_edge(i+1,H+j+1,1)
            F.add_edge(H+j+1,i+1,1)

if sy==gy or gx==gy:
    print(-1)
    exit()
print(F.max_flow(0,H+W+1))
