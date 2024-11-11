k=int(input())
if k==1:
    print(6)
else:
    x=(k//2)
    y=k%2
    ans=""
    if x+y>18:
        print(-1)
    else:
        for i in range(x):
            ans+="8"
        for i in range(y):
            ans+="0"
        if int(ans)>1e18:
            print(-1)
        else:
            print(ans)
    
