n,m,k=map(int,input().split())
l=list(map(int,input().split()))
s=0
g=0
for i in range(m-2,0,-1):
    if(l[i]!=0 and l[i]<=k):
        s=(m-1)-i
        break
for i in range(m,n):
    if(l[i]!=0 and l[i]<=k):
        g=i-(m-1)
        break
if(s==0):
    print(g*10)
elif(g==0):
    print(s*10)
else:
    print(min(s,g)*10)
        
