b=[]
n=int(input(""))
b=list(map(int,input().split()[:n]))
m=int(input(""))
for i in range(m):
    x,y=map(int,input().split())
    x-=1
    if(x!=0):
        b[x-1]+=y-1
    if(x!=n-1):
        b[x+1]+=b[x]-y
    b[x]=0
for i in range(n):
    print(b[i])
        
        
