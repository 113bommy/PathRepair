n=int(input())
t=n
ar=[]
while(t>0):
    ar.append(t)
    if t%2==0:
        t=t//2
    else:
        t-=1
class Graph():
    def __init__(self):
        self.vertices=set()
        self.edges=[]
    def addedge(self,a,b,w):
        self.edges.append([a,b,w])
        self.vertices.add(a)
        self.vertices.add(b)
g=Graph()
g.addedge(0,1,0)
g.addedge(0,1,1)
for i in range(3,len(ar)+1):
    if ar[-i]==ar[-i+1]+1:
        g.addedge(0,len(g.vertices)-1,ar[-1]-1)
    else:
        for j in g.edges:
            j[2]*=2
        g.addedge(len(g.vertices)-1,len(g.vertices),0)
        g.addedge(len(g.vertices)-2,len(g.vertices)-1,1)


print(len(g.vertices),len(g.edges))

for i in g.edges:
    print(i[0],i[1],i[2])



