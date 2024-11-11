t=int(input())
for _ in range(t):
    n,x,m=map(int,input().split())
    depend=[]
    for k in range(m):
        depend.sort()
        l,r=map(int,input().split())
        if(l<=x and r>=x):
            depend.append([l,r])
            continue
        rr=len(depend)
        for i in range(rr):
            if((depend[i][0]<=l and depend[i][1]>=l) or(depend[i][0]<=r and depend[i][1]>=r)):
                depend.append([l,r])
                break
    depend.sort()
    if(len(depend)==0):
        print(0)
        continue
        
    
    start=depend[0][0]
    end=depend[0][1]
    ans=end-start+1
   
    
    for i in range(1,len(depend)):
        if(depend[i][0]!=start):
            if(depend[i][0]<=end):
                if(depend[i][1]>=end):
                    sub=end-depend[i][0]+1
                    ans=ans+(depend[i][1]-depend[i][0]+1)-sub
                    end=depend[i][1]
                    
                else:
                    continue
            else:
        
                ans=ans+(depend[i][1]-depend[i][0]+1)
                start=depend[i][0]
                end=depend[i][1]
        else:
                sub=depend[i][1]-end
                ans=ans-(end-start+1)
                ans=ans+(depend[i][1]-depend[i][0]+1)
                end=depend[i][1]
        
    print(ans)
