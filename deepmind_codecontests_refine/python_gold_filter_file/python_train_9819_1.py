t=int(input())
for i in range(t):
    n=int(input())
    ans=0
    number=2050*(10**15)
    while(True):
        if n<2050:
            break
        if n>=number and number>=2050:
            n-=number
            ans+=1
        else:
            number=number//10
    if n!=0:
        print(-1)
    else:
        print(ans)
        
        
        