from collections import defaultdict
class Graph:
    def __init__(self,cat,k,n):
        self.graph = defaultdict(list)
        self.visited = [False] * (n+3)
        self.CAT = cat
        self.CATDICT = defaultdict(int)
        self.k = k
        self.cat = 0
        self.restau = 0
    def addEdge(self,fr,to):
        self.graph[fr].append(to)
        self.graph[to].append(fr)
    def BFS(self,root):
        # if(len(self.graph[root])<2):
        #     if(self.k>0):
        #         self.restau+=1
        queue = [root]
        self.visited[root] = True
        if(self.CAT[0]==1):
            self.CATDICT[1] = 1
        while queue:
            # print("QUEUE: ",queue)
            s = queue.pop(0)
            leaf = True
            for i in self.graph[s]:
                if(self.visited[i]==False):
                    self.visited[i] = True
                    leaf = False
                    if(self.CAT[i-1]==1):
                        self.CATDICT[i] = self.CATDICT[s]+1
                    if(self.CATDICT[i]<=self.k):
                        queue.append(i)
            if(leaf==True):
                if(self.CATDICT[i]<=k):
                    self.restau+=1
    def solve(self):
        # print()
        print(self.restau)
M,k = map(int,input().split())
cat = [int(x) for x in input().split()]
G = Graph(cat,k,M-1)
for i in range(M-1):
    fr,to = map(int,input().split())
    G.addEdge(fr,to)
G.BFS(1)
G.solve()