
for _ in range(int(input())):
    n,d=map(int,input().split())
    l=list(map(int,input().split()))
    
    paths=[]
    d=n-d
    s=set()
    for i in range(n):
        if i in s:
            continue
        path=[]
        path.append(l[i])
        s.add(i)
        j=(i+d)%n
        
        while j<n and j not in s:
            path.append(l[j])
            s.add(j)
            j=(j+d)%n
        
        paths.append(path)
    
    ans=0
    for path in paths:
        i=0
        n1=len(path)
        if 0 not in path:
            ans=-1
            break
        while i<n1:
            if path[i]==0:
                i+=1
                continue
            else:
                j=i+1
                while j<n1 and  path[j]==1:
                    j+=1
                ans=max(j-i,ans)
                i=j
    print(ans)           