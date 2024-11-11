for i in range(int(input())):
    n=int(input())
    ans=4*n
    for x in range(n):
        if x == n-1:
            print(ans)
        else:
            print(ans,end=' ')
            ans-=2
        
