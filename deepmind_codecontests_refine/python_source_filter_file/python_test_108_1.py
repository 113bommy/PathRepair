import sys,os,io
import math 
from bisect import bisect_right
from collections import defaultdict
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
else:
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


#for deep recursion__________________________________________-
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


xx = []
pp = []
dicti = defaultdict(lambda:-1)
cnt = 0
# A function used by DFS

@bootstrap
def DFSUtil(v,visited,graph):
    global xx
    # Mark the current node as visited and print it
    visited[v]= True
    xx.append(v)
    #Recur for all the vertices adjacent to this vertex
    for i in graph[v]:
        if visited[i]==False:
            yield DFSUtil(i,visited,graph)
    yield


@bootstrap
def fillOrder(v,visited, stack,graph):
    visited[v]= True
    for i in graph[v]:
        if visited[i]==False:
            yield fillOrder(i, visited, stack,graph)
    stack = stack.append(v)
    yield
    

# Function that returns reverse (or transpose) of this graph
def getTranspose(graph,n):
    tg = [[] for i in range(n)]
    # Recur for all the vertices adjacent to this vertex
    for i in range(len(graph)):
        for j in graph[i]:
            tg[j].append(i)
    return tg



# The main function that finds and prints all strongly
# connected components
def printSCCs(n,graph):
    global xx,pp,cnt
    stack = []
    # Mark all the vertices as not visited (For first DFS)
    visited =[False]*(n)
    # Fill vertices in stack according to their finishing
    # times
    for i in range(n):
        if visited[i]==False:
            fillOrder(i, visited, stack,graph)

    # Create a reversed graph
    gr = getTranspose(graph,n)
    
    # Mark all the vertices as not visited (For second DFS)
    visited =[False]*(n)

    # Now process all vertices in order defined by Stack
    # print(stack)
    cnt = 0
    while stack:
        i = stack.pop()
        if visited[i]==False:
            DFSUtil(i, visited,gr)
            pp = xx[:]
            for j in xx:
                dicti[j]=cnt
            xx = []
            cnt += 1
    newg = [[] for i in range(n)]
    for i in range(n):
        for j in gr[i]:
            newg[dicti[i]].append(dicti[j])
    for i in range(n):
        newg[i]=list(set(newg[i]))
    # print(newg)
    node = cnt-1
    # print(node)
    vis = [False]*n 
    vis[node]=True 
    st = [node]
    while st:
        node = st.pop(-1)
        for kid in newg[node]:
            if vis[kid]==False:
                vis[kid]=True 
                st.append(kid)
    res = ['0']*n 
    if vis.count("False")==0:
        for i in pp:
            res[i]='1'
    print(''.join(res))
    



def solve():
    n = ii()
    a = li()
    b = li()
    first = []
    second = []
    first = a[:]
    second = b[:]
    d1 = {}
    d2 = {}
    e = defaultdict(lambda:0)
    for i in range(n):
        d1[a[i]]=i
        d2[b[i]]=i

    first.sort()
    second.sort()
    g = [[] for i in range(n)]
    # print(first)
    for i in range(n):
        p1 = bisect_right(first,a[i])

        if p1<n:
            p1 = d1[first[p1]]
            if e[(i,p1)]==0:
                g[i].append(p1)
                e[(i,p1)]=1

        
        p2 = bisect_right(second,b[i])
        if p2<n:
            p2 = d2[second[p2]]
            # print(i,p2)
            if e[(i,p2)]==0:
                g[i].append(p2)
                e[(i,p2)]=0
    
    for i in g:
        print(*i)
    printSCCs(n,g)
    # print("______________")


            


t = 1
t = ii()
for _ in range(t):
    solve()
