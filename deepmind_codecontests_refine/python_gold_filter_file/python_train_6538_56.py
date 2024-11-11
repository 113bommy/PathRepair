from collections import deque
h,w=map(int,input().split())
l=[]
l.append('@'*(w+2))
for i in range(h):
    l.append('@'+input()+'@')
l.append('@'*(w+2))
q=deque()
p=[[-1 for i in j] for j in l]
for i in range(1,h+1):
    for j in range(1,w+1):
        if l[i][j]=='#':
            q.append([i,j])
            p[i][j]=0
while len(q)>0:
    x,y=q.popleft()
    for i,j in [[1,0],[-1,0],[0,-1],[0,1]]:
        if l[x+i][y+j]=='.' and p[x+i][y+j]==-1:
            q.append([x+i,y+j])
            p[x+i][y+j]=p[x][y]+1
a=0
for i in p:
    for j in i:
        a=max(a,j)
print(a)
#print(*p,sep='\n')