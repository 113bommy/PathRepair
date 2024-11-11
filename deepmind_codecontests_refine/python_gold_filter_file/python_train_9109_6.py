n, x1, y1, x2, y2 =map(int,input().split())
lis=[]
ans=[]
r1=r2=0
for i in range(n):
    a,b=map(int,input().split())
    lis.append([a,b])
    k=(x1-a)**2+(y1-b)**2
    l=(x2-a)**2+(y2-b)**2
    ans.append([k,l])
ans.sort(reverse=True)
ans.append([0,0])
r1=ans[0][0]
r2=0
fin=r1+r2
#print(ans)
for i in range(1,n+1):
    r1=ans[i][0]
    r2=max(r2,ans[i-1][1])
    fin=min(r1+r2,fin)
print(fin)    
