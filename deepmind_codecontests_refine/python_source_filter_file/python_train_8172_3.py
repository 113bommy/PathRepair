d={}
d1={}
sm=0
sh=[]
n=int(input())
for i in range(n):
    sh.append(list(map(int,input().split())))
for i in range(n):
    x=sh[i][0]
    y=sh[i][1]
    sm+=d.get(x+y,0)
    sm+=d1.get(x-y,0)
    d[x+y]=d.get(x+y,0)+1 
    d1[x-y]=d.get(x-y,0)+1
print(sm)