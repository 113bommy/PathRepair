for _ in range(int(input())):
    b,m,k=map(int,input().split())
    pm,pk=map(int,input().split())
    if(pm<pk):
        m,k=k,m
        pm,pk=pk,pm
    b//=2;
    x=min(b,m)
    b-=x
    res=x*pm
    x=min(b,k)
    res+=x*pk
    print(res)