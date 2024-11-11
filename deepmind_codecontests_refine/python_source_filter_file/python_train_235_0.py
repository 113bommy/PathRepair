
for _ in range(int(input())):
    s=input()
    n=len(s)
    used=[False]*n
    ans=0
    for i in range(1,len(s)-1):
        flag=0
        if s[i]==s[i-1] and used[i-1]==False:
            flag=1
        if i>1 and s[i]==s[i-2] and used[i-2]==False:
            flag=1
        if flag==1:
            used[i]=True
            ans+=1
    print(ans)
    
            
            
            