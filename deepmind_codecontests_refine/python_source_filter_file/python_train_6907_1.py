import heapq
def path(source,destination):
    path=[]
    par=[]
    dis=[]
    vis=[]
    for i in range(n+1):
        dis.append(1000000000000)
        vis.append(False)
        par.append(-1)
    dis[source]=0
    q=[]
    heapq.heappush(q,(0,source))
    while q:
        next_item = heapq.heappop(q)
        node=next_item[1]
        #print(node)
        if vis[node]:
            continue
        vis[node]=True
        i=1
        flag=False
        for item in cell_adj[node]:
           if item!=0:
               if(dis[item]>(dis[node]+cell_wei[node][i])):
                    dis[item]=min(dis[item],dis[node]+cell_wei[node][i])
                    par[item] = node
                    heapq.heappush(q,(dis[item],item))
               i=i+1
               '''
               if (item == destination):
                   flag=True
                   break
        if (flag):
            break'''
    #print("parent")
    #print(destination)
    path.append(destination)
    while(par[destination]!=-1):
       # print(par[destination])
        path.append(par[destination])
        destination=par[destination]
    path.reverse()
    if(path[0]!=-1):
        print(-1)
        return;
    for len in (path):
        print(len)
    return path


n,m= input().split()
n=int(n)
m=int(m)
cols=1
cell_adj = [[0 for i in range(1)] for j in range(n+1)]
cell_wei = [[0 for k in range(1)] for l in range(n+1)]
for i in range(m):
    a,b,w= input().split()
    a=int(a)
    b=int(b)
    w=int(w)
    cell_adj[a].append(b)
    cell_adj[b].append(a)
    cell_wei[a].append(w)
    cell_wei[b].append(w)

ans=path(1,n)
#for ele in (ans):
    #print(ele)
