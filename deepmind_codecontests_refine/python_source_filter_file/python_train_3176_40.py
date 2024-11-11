a,b= map(int,input().split())

if b==2:
    ans=10**a-2
    print(ans)
elif b==3 or b==9:
    ans=10**a-1
    print(ans)
elif b==4:
    if a==1:
        ans=10-6
        print(ans)
    else:
        ans=10**a-4
    print(ans)
elif b==5:
    ans=10**a-5
    print(ans)
elif b==6:
    ans=10**a-4
    print(ans)
elif b==10:
    if a==1:
        print(-1)
    else:
        ans=10**(a-1)
        print(ans)
elif b==7 or b==8:
    ans=b*(10**(a-1))
    print(ans)
