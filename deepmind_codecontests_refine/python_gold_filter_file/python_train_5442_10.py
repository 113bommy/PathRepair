for _ in range(int(input())):
    n=int(input())
    k=str(input())
    if n%2==0:
        ans=1
        for i in range(1,n,2):
            if int(k[i])%2==0:
                ans=2
                break
    else:
        ans=2
        for j in range(0,n,2):
            if int(k[j])%2==1:
                ans=1
                break
    print(ans)        
