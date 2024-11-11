import collections
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    ans,c,m=0,0,0
    v=collections.Counter(a)
    for i in range(1001):
        c=0
        for j in v:
            if j>=i:
                c+=v[j]
        if c>=i:
            ans=max(ans,i)
        else:
            break
    print(ans)
        
    
