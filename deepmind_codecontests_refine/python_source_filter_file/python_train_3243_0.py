n,b,a=map(int,input().split())
s=list(map(int,input().split()))
i=0
aa=a
bb=b
while (bb>0  or aa>0) and i<n:
    if s[i]==0:
        if aa>0:
            aa-=1
        else:
            bb-=1
    else:
        if aa==a or b==0:
            aa-=1
        else:
            bb-=1
            aa+=1
    i+=1        
            
            
            
            
    
    
    # if aa==a or (bb==0 and aa>0):
    #     aa-=1
    # else:
    #     if s[i]==1:
    #         aa+=1
    #     bb-=1
    # i+=1
    # # print(aa,bb,i)

print(i)

        
    
    
    