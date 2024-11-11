for _ in range(int(input())):
    s=input()
    
    a,b,c=-1,-1,-1
    ans=1000
    for i in range(len(s)):
        
        k=int(s[i])-1
    
        if k==0:
            a=i
        if k==1:
            b=i
        if k==2:
            c=i
        if a!=-1 and b!=-1 and c!=-1:
            #print(a,b,c)
            ans=min(ans,max(a,b,c)-min(a,b,c)+1)
            
    
    if ans==1000:
        print(0)
    else:
        print(ans)