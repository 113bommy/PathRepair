
t=int(input())
for _ in range(t):
    s=list(input())
    n=len(s)
    x=int(input())
    ans=[-1]*n
    flag=0
    for i in range(n):
        if s[i]=='0':
            if i+x<n:
                ans[x+i]=0
            if i-x>=0:
                ans[i-x]=0
        else:
            if i-x>=0:
                ans[i-x]=1
            if i+x<n:
                ans[x+i]=1
    #print(ans)
    res=[-1]*n
    for i in range(n):
        if i-x>=0 and ans[i-x]==1:
            res[i]='1'
        elif i+x<n and ans[i+x]==1:
            res[i]='1'
        else:
            res[i]='0'
    #print(res)
    for i in range(n):
        if s[i]!=res[i]:
            #print('i:',i)
            print(-1)
            flag=1
            break
    if flag:
        continue
    #for i in range(n):
    print(*ans,sep='')
            
            
            
            