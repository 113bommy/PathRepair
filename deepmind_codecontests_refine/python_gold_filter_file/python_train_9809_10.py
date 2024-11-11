t = int(input())
for _ in range(t):
    n,x = map(int, input().split())
    s = input()
    b = list()
    if s[0]=='1':
        b.append(-1)
    else:
        b.append(1)
    for i in range(1,n): 
        if s[i]=='1':
            b.append(b[-1]-1)
        else:
            b.append(b[-1]+1)
    
    ans=0
    k=b[-1]
    if x==0:
        ans+=1
    if k>0:
        for i in range(n):
            if b[i]%k==x%k and b[i]<=x:
                ans+=1
    elif k==0:
        for i in range(n):
            if b[i]==x:
                ans=-1
                break
    else:
        for i in range(n):
            if b[i]%(-k)==x%(-k) and b[i]>=x:
                ans+=1

    print(ans)