



a=int(input())
for i in range(a):
    s=int(input())
    s=input()
    ans=[]
    for i in range(len(s)):
        if(s[i]=='L'):
            ans.append(1)
        else:
            ans.append(0)
    bac=[]
    
    for i in range(len(ans)):
        if(ans[i]==0):
            bac.append(0)
            continue;
        if(i==0 and ans[i]==1):
            bac.append(1)
            continue;
        if(ans[i]==1):
            if(i>=2):
                if(bac[-1]==0):
                    bac.append(bac[-2]+2)
                else:
                    bac.append(1)
            else:
                if(ans[0]==0):
                    bac.append(2)
                else:
                    bac.append(1)
        
            
    forw=[0 for i in range(len(ans))]
    for i in range(len(ans)-2,-1,-1):
        if(ans[i+1]==1):
            forw[i]=0
            continue;
        else:
            if(i+2<=len(ans)-1 and ans[i+2]==1):
                forw[i]=forw[i+2]+2
            elif(i+2<=len(ans)-1 and ans[i+2]==0):
                forw[i]=1

            elif(i+1<=len(ans)-1):
                if(ans[i+1]==0):
                    forw[i]=1
                else:
                    forw[i]=0
    
   
    fin=[0 for i in range(len(forw)+1)]
    for i in range(len(bac)):
        fin[i+1]=bac[i]+forw[i]+1

    cnt=0

    for i in range(len(s)):
        if(i%2==0):
            if(s[i]=='R'):
                cnt+=1
            else:
                break;
        else:
            if(s[i]=='L'):
                cnt+=1
            else:
                break;
    fin[0]=cnt+1
    
    print(*fin)
    
        
       
            
        
    






        
