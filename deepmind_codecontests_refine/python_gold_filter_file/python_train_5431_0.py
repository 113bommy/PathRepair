a=int(input())
ans=[]
aller=[0 for i in range(a)]
for i in range(a):
    s=input()
 
    if(s[0]=='-'):
        s=s[1::]
        t=s.find('.')
        q=int(s[0:t])
        m=s[t+1:]
        ans.append(-q)
        if(len(m)==m.count('0')):
            aller[i]=0
            
            continue;

        aller[i]=1 #+1 not allowed
        
    else:
        t=s.find('.')
        q=int(s[0:t])
        ans.append(q)
        m=s[t+1:]
        if(len(m)==m.count('0')):
            aller[i]=0
            continue;
        aller[i]=-1 # -1 not allowed
alpha=sum(ans)

for i in range(len(ans)):
    if(alpha==0):
        continue;
    if(aller[i]==0):
        continue;
    if(aller[i]==1 and alpha>0):
        ans[i]-=1
        alpha-=1
        continue;
    if(aller[i]==-1 and alpha<0):
        ans[i]+=1
        alpha+=1
        continue;
for i in range(len(ans)):
    print(ans[i])



    


    
    
