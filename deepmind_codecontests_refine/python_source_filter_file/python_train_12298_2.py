n,p1,p2,p3,t1,t2=map(int,input().split())
ans,l1,r1=0,0,0
for i in range(n):
    l2,r2=map(int,input().split())
    ans+=(r2-l2)*p1
    if l1!=0:
        t=l2-r1
        ans+=min(t1,t)*p1+min(max(t-t1,0),t2)*p2+max(t-t1-t2,0)*p3
    l1,r1=l2,r2
print(ans)
    
