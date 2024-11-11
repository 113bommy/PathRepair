import math
for _ in range(int(input())):
    n,g,b=map(int, input().split())
    if g>=b:
        print(n)
    else:
        m=n
        n+=1
        n//=2
        if n<=g:
            print(m)
        else:
            ans=((n-1)//g)*(g+b)
            if n%g:
                ans+=n%g
            else:
                ans+=g
            print(int(ans))