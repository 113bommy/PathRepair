for _ in range(int(input())):
    _=input()
    tmp=input()
    
    n=map(int,tmp.split())
    n=list(n)
    for i,x in enumerate(n):
        
        if x==1:
            break
    a=b=i+1
    MAX=1
    ans=[1]
    n=[float('inf')]+list(n)+[float('inf')]
    
    for i in range(2,len(n)-1):
        
        if n[a-1]>n[b+1]:
            MAX=max(n[b+1],MAX)
            b+=1
        else:
            MAX=max(n[a-1],MAX)
            a-=1
        if MAX==i:
            ans.append(1)
        else:
            ans.append(0)
    for i,x in enumerate(ans):
        ans[i]=str(x)
    print(' '.join(ans))