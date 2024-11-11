for _ in range(int(input())):
    x=int(input())
    ans=0;ref=1
    while(1):
        if(ref==x):
            ans+=1
        if(ref>x):
             break
        else:
            ans+=x//ref
        ref*=2
    print(ans)