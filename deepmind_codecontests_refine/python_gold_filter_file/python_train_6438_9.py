class Node:
    def __init__(self):
        pass

class Edge:
    def __init__(self,edge,cost=1):
        self.node_from=edge[0]
        self.node_to=edge[1]
        self.cost=cost

    def add_node(self,node):
        self.nodes.append(node)

class myGraph:

    def __init__(self):
        self.adj={}
        self.nodes={}

    def add_edge(self,edge,cost):
        if len(edge)==1:
            edge=list(edge)

        u,v=edge[0],edge[1]

        if u not in self.nodes:
            self.adj[u] = {}
            self.nodes[u] = {}

        if v not in self.nodes:
            self.adj[v] = {}
            self.nodes[v] = {}

        # add the edge
        self.adj[u][v] = cost
        self.adj[v][u] = cost

    def add_directed_edge(self,edge,cost):
        if len(edge)==1:
            edge=list(edge)


        u,v=edge[0],edge[1]

        if u not in self.nodes:
            self.adj[u] = {}
            self.nodes[u] = {}

        if v not in self.nodes:
            self.adj[v] = {}
            self.nodes[v] = {}

        self.adj[u][v] = cost

    def get_edges_from(self,node):
        return [(self.adj[node][nn],node,nn) for nn in self.adj[node]]


    def makeEdgeobj(self):
        edges=[]
        for sn in self.nodes:
            for e in self.get_edges_from(sn):
                edges.append(Edge([e[1],e[2]],e[0]))

        return edges

    def _add(self,edges,add_edges):
        for e in add_edges:
            hq.heappush(edges,e)
        return edges

    def bermn_ford(self,start,init=0):

        nodes=self.nodes
        dists={}
        for n in nodes:
            dists[n]=float("inf")

        dists[start]=init
        edges=self.makeEdgeobj()

        for i in range(len(nodes)):
            update=False
            for k in range(len(edges)):
                e=edges[k]
                if  dists[e.node_from]!=float("inf") and dists[e.node_to]>dists[e.node_from]+e.cost:
                    dists[e.node_to]=dists[e.node_from]+e.cost
                    update=True

            if i==len(nodes)-1:
                return False

            if not update:
                break

        return dists


    def dijkstra(self,start, goal=None):
        import heapq
        '''
            get minimum cost
        '''

        N = len(self.adj)          # グラフのノード数
        #dist = [float('inf') for i in range(N)] # 始点から各頂点までの最短距離を格納する
        dist = {k:float('inf') for k in self.nodes}
        #prev = [float('inf') for i in range(N)]

        dist[start] = 0
        visited = []

        koho=[]
        heapq.heappush(koho,(0,start))

        vtx=list(self.nodes)
        vtx.remove(start)

        while len(koho)!=0:
            d,mini=heapq.heappop(koho)

            if d>2:
                break

            if dist[mini]<d:
                continue


            for k in list(self.adj[mini]):
                cost=self.adj[mini][k]
                if cost != float('inf') and dist[k]>dist[mini]+cost:# and not(k in visited):
                    dist[k]=dist[mini]+cost
                    heapq.heappush(koho,(dist[k],k))
                    #prev[k]=mini

        return dist




def spaceinput():
    s=input()
    if len(s)==0:
        return False

    return list(map(int,s.split(" ")))

if __name__=="__main__":
    n,m=spaceinput()
    g=myGraph()

    for i in range(10**6):
        try:
            ss=spaceinput()
            if not ss:
                break
        except:
            break

        g.add_edge((ss[0],ss[1]),1)
    res=g.dijkstra(start=1)
    #print(res)
    if n in res and res[n]<=2:
        if res[n]==1:
            if len(set(g.adj[1]).union(g.adj[n]))>0:
                print("POSSIBLE")
            else:
                print("IMPOSSIBLE")
        else:
            print("POSSIBLE")
    else:
        print("IMPOSSIBLE")
