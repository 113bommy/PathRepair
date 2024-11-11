import sys,threading

from queue import Queue
from collections import defaultdict
class graph1:
    def __init__(self,vertices):
        self.vertices = vertices
        self.adjlist = defaultdict(list)
    
    def addedge(self,v1,v2):
        self.adjlist[v1].append(v2)
        self.adjlist[v2].append(v1)
        
    def bfshelper(self,v1,visited,d):
        q = Queue(maxsize = self.vertices)
        visited[v1]=True
        q.put((v1,0))
        while(not (q.empty())):
            k= q.get()
            d[k[1]]+=1
            print(d[k],k,'height')
            for i in self.adjlist[k[0]]:
                if visited[i]==False:
                    q.put((i,k[1]+1))
                    visited[i]=True        
    def bfs(self,v1,k):
        visited = [False for i in range(self.vertices)]
        level  = []
        d= defaultdict(int)
        self.bfshelper(v1,visited,d)
        print(d)
        l = len(d.keys())
        ans = 0
        level  =l
        while(k>0):
            m = min(k,d[level-1])
            ans+=((level-1)*m)
            k-=m
            level-=1
        return ans
    
    def dfshelper(self,v1,visited,h,d,parent,count):
        #print(v1,end = ' ')
        visited[v1] = True
        count[v1]=1
        for i in self.adjlist[v1]:
            if visited[i]==False:
                self.dfshelper(i,visited,h+1,d,v1,count)

        count[parent]+=count[v1]
        #print('count is',count)
        d[v1] = (h-(count[v1]-1))
        
    def dfs(self,v1,e):
        visited = [False for i in range(self.vertices+1)]
        count = [0 for i in range(self.vertices+1)]
        d ={}
        d[v1] = 0
        self.dfshelper(v1,visited,0,d,0,count)
        l = []
        for i in range(1,self.vertices):
            l.append(d[i])
        return sum(sorted(l,reverse=True)[:e])

def main():             
    n,e = [int(i) for i in input().split()]
    g = graph1(n+1)
    for i in range(n-1):
        a,b =list(map(int,input().split()))
        g.addedge(a,b)
    print(g.dfs(1,e))

if __name__ == "__main__":
    sys.setrecursionlimit(2*10**6)
    threading.stack_size(102400000)
    thread = threading.Thread(target=main)
    thread.start()
    thread.join()     
            
        
    
    