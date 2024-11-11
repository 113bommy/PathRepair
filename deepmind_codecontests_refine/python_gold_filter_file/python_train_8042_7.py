import math
for _ in range(int(input())):
    n=int(input())
    if n==1:
        print(8)
    else:
        q=(n//4)
        r=n%4
        ans='9'*(n-q-1)
        if r==1:
            ans+='8'
        elif r==2:
            ans+='8'
        elif r==3:
            ans+='8'
        else:
            ans+='9'
        ans+='8'*(q)
        print(ans)