import sys
input = sys.stdin.readline
#lev contains height from root,lower neighbour, higher neighbours
#lev[0] contains 0 (because it is the root), higher neighbours (=neighbours)
n,m=map(int,input().split())

neig=[0]*n
for i in range(n):
    neig[i]=[0]

for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    neig[a][0]+=1
    neig[b][0]+=1
    neig[a].append(b)
    neig[b].append(a)

sol=-1
isconnected=[False]*n
notinacomponent=[0]*n
for i in range(n-1):
    notinacomponent[i]=i
treated=0
while treated<n:
    todo=[notinacomponent.pop()]
    treated+=1
    sol+=1
    while len(todo)>0:
        v=todo.pop()
        for i in range(1,neig[v][0]+1):
            isconnected[neig[v][i]]=True
        newnotin=[]
        for u in notinacomponent:
            if isconnected[u]:
                newnotin.append(u)
            else:
                treated+=1
                todo.append(u)
        notinacomponent=newnotin
        for i in range(1,neig[v][0]+1):
            isconnected[neig[v][i]]=False
print(sol)