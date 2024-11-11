
class disjoint:
    def __init__(self,n):
        self.rank=[1]*n
        self.parent=[i for i in range(n)]
       
        
    def find(self,x):
        if(self.parent[x]!=x):
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x];
       
    def union(self,x,y):
        
        xid=self.find(x)
        yid=self.find(y)
      
        if(xid==yid):
            return;
        if(self.rank[xid]<self.rank[yid]):
            self.parent[xid]=yid
            
            return;
        elif(self.rank[xid]>self.rank[yid]):
            self.parent[yid]=xid # merging y into x
          
            return;
        else:
            self.parent[yid]=xid
            self.rank[xid]+=1
            
            return;        
    
import sys
input=sys.stdin.readline
n,m,w=map(int,input().split())
obj=disjoint(n)
z=list(map(int,input().split()))
be=list(map(int,input().split()))
ans=[]

for i in range(len(z)):
    ans.append([i,z[i],be[i]])

for i in range(m):
    p,q=map(int,input().split())
    obj.union(p-1,q-1)
from collections import *

al=defaultdict(list)
for i in range(len(ans)):
    y=obj.find(ans[i][0])
    al[y].append(ans[i][0])
print(al)
dp=[[0 for i in range(len(al)+1)] for i in range(w+1)]
c1=0
maxa=0
for i in al:
    if(c1==0):
        q=al[i]
        total=0
        bea=0
        for x in q:
            
            wei=ans[x][1]
           
            if(wei<=w):
                dp[wei][c1]=max(dp[wei][c1],ans[x][2])
                maxa=max(maxa,dp[wei][c1])
            total+=wei
            bea+=ans[x][2]
        
        if(total<=w):
            dp[total][c1]=max(dp[total][c1],bea)
            maxa=max(maxa,dp[total][c1])
        c1+=1
        
    else:
        q=al[i]
        total=0
        dil=0
        bea=0
        wei=0
        for x  in q:
            
            wei=ans[x][1]
            bea=ans[x][2]
            total+=wei
            dil+=bea
            for j in range(w+1):
                
                if(wei>j):
                    dp[j][c1]=max(dp[j][c1-1],dp[j][c1])
                    maxa=max(maxa,dp[j][c1])
                    continue;
                else:
                    dp[j][c1]=max(dp[j][c1],dp[j-wei][c1-1]+bea,dp[j][c1-1])
                    maxa=max(maxa,dp[j][c1])
        if(total<=w):
            dp[total][c1]=max(dp[total][c1-1],dil,dp[total][c1])
        
            maxa=max(maxa,dp[total][c1])
            for j in range(w+1):
                if(j<=total):
                    continue;
                else:
                    dp[j][c1]=max(dp[j][c1],dil+dp[j-total][c1-1])
                    maxa=max(maxa,dp[j][c1])
        c1+=1

print(maxa)














    

    
