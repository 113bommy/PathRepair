s=input()
n=len(s)
l=[[0,0,0] for i in range(n)]
ans=0
x=int(s[0])%3
if(x==0):
    ans+=1
else:
    l[0][x]=1
for i in range(1,n):
    x=int(s[i])%3
    if(x==0):
        ans+=1
        continue
    
    if(l[i-1][3-x]>0):
        ans+=1
        l[i][3-x]=0
        l[i][x]=l[i-1][x]
    else:
        if(l[i-1][x]!=0):
            l[i][1]=1
            l[i][2]=1
        else:
            l[i][x]=1

print(ans)