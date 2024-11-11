N=int(input())
t=[0]*N
r=set(range(N))
for _ in[0]*N:
 x,y,z=list(map(int,input().split()))
 t[x]=[y,z]+[0]*2+[(y!=-1)+(z!=-1)]+[0]*2
 r-={y,z}
def f(i,p,s,d):
 if i<0:return-1
 l,r=t[i][:2]
 t[i][2:]=[p,s,t[i][4],d,max(f(l,i,r,d+1),f(r,i,l,d+1))+1]
 return t[i][-1]
f(r.pop(),-1,-1,0)
for i in range(N):
 print('node {}: parent = {}, sibling = {}, degree = {}, depth = {}, height = {}, {}'.format(i,*t[i][2:],'root'if not t[i][5]else'internal node'if t[i][4]else'leaf'))
