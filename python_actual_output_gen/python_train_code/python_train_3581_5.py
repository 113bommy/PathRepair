x0,y0,ax,ay,bx,by=map(int,input().split())
xs,ys,t=map(int,input().split())
node=[[x0,y0]]
x=x0
y=y0
while x<=10**16 and y<=10**16:
    x=x*ax+bx
    y=y*ay+by
    node.append([x,y])
n=len(node)
d=[]
d_s=[]
for i in range(n-1):
    d.append(sum(node[i+1])-sum(node[i]))
for i in range(n):
    d_s.append(abs(node[i][0]-xs)+abs(node[i][1]-ys))
dd=[0]
for i in range(n-1):
    dd.append(dd[-1]+d[i])
ans=0
for i in range(n-1):
    for j in range(i+1,n):
        i_j=dd[j]-dd[i]
        if min(i_j+d_s[i],i_j+d_s[j])<=t:
            ans=max(ans,j-i+1)
print(ans)