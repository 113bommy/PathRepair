    
import heapq
 
n,k=map(int,input().split())
 
st=[]
L=[0]*(200005)
for i in range(0,n):
    l,r=map(int,input().split())
    st.append((r,l,i+1))
    L[l]+=1
    L[r+1]-=1
 
pre=[0]
for i in range(1,len(L)):
    pre.append(pre[-1]+L[i])
 
st2=sorted(st)
st2=st2[::-1]
 
dp=[]
for i in range(0,200005):
    h=[]
    dp.append(h)
 
 
for i in range(0,len(st2)):
    dp[st2[i][1]].append(i+1)
    dp[st2[i][0]+1].append(-i-1)
 
#print(st2)
#print('pre',pre[25:31]) 
tot=0
ans=[]
 
 
pos=[0]*(200005)
yaad=[0]*(n+2)
q=[]
heapq.heapify(q)
c=0
for i in range(1,40):
    #print(i,q)
    c=c+pos[i]
    for j in range(0,len(dp[i])):  
        if(dp[i][j]>0):
            yaad[dp[i][j]]+=1
            heapq.heappush(q,dp[i][j])
        else:
            yaad[-dp[i][j]]-=1
    #print(i,q,c)
    if(pre[i]-c>k):
        c2=0
        while(pre[i]-c>k):
            tt=heapq.heappop(q)
            if(yaad[tt]>0):
                tot+=1
                ans.append(st2[tt-1][2])
                pos[st2[tt-1][0]+1]-=1
                c2+=1
                pre[i]-=1
        c+=c2
        
if(len(ans)>0):
    ans=sorted(ans)
print(tot)
print(*ans)
 
                
    
    
 