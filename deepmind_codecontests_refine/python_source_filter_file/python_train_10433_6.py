import sys
input = sys.stdin.readline

x0,y0,ax,ay,bx,by=(map(int,input().split()))
xs,ys,t=(map(int,input().split()))

x=x0
y=y0
A=[]
B=[]
MAX=66
for i in range(MAX):
    A.append(x)
    B.append(y)
    x=x*ax+bx
    y=y*ay+by
ans=0

def dis(x,y):
    return abs(A[x]-A[y])+abs(B[x]-B[y])

for i in range(MAX):
    for j in range(MAX):
        distance=0
        distance=abs(xs-A[i])+abs(ys-B[i])
        distance+=dis(i,j)
        print(i,j,distance)
        if distance<=t:
            ans=max(ans,abs(i-j)+1)
print(ans)
