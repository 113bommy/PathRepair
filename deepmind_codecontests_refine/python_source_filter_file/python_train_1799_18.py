for t in range(int(input())):
    n=int(input())
    now,ans=int(1),int(0)
    while(1):
        n-=now*(now+1)/2
        if(n<0): break
        ans+=1
        now=2*now+1
    print(ans)

