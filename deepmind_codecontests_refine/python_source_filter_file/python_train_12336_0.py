s,t="$"+input(),"$"+input()
n,m=len(s)-1,len(t)-1
ar=[[0]*(m+1) for i in range(n+1)]
for i in range(1,n+1):ar[i][0]=i
for j in range(1,m+1):ar[0][j]=i
for i in range(1,n+1):
    for j in range(1,m+1):
        if(s[i]==t[j]):ar[i][j]=ar[i-1][j-1]
        else:ar[i][j]=min(ar[i-1][j],ar[i-1][j-1],ar[i][j-1])+1
x,y=n,m
res=[]
while(x+y):
    if(s[x]==t[y]):
        x-=1
        y-=1
    elif(x and y and ar[x-1][y-1]+1==ar[x][y]):
        res.append(["REPLACE",x,t[y]])
        x-=1
        y-=1
    elif(x and ar[x-1][y]+1==ar[x][y]):
        res.append(["DELETE",x])
        x-=1
    else:
        res.append(["INSERT",x+1,t[y]])
        y-=1
#res=res[::-1]
print(len(res))
for e in res:
    print(*e)
