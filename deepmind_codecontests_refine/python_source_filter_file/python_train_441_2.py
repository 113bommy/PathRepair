for t in range(int(input())):
    n=int(input())
    
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    ans=[]
    ans.append(a[0])
    for i in range(1,n-1):
        if(a[i]!=ans[i-1]):
            ans.append(a[i])
        else:
            ans.append(b[i])
    if(a[i+1]!=ans[i-1] and a[i+1]!=ans[0]):
        ans.append(a[i+1])
    elif (b[i+1]!=ans[i-1] and b[i+1]!=ans[0]):
        ans.append(b[i+1])
    else:
        ans.append(c[i+1])
        
    print(*ans)
    
    