import math
for _ in range(int(input())):
    l1=list(map(int,input().split()))
    n=l1.pop()
    l1.sort()
    a=l1.pop(0)
    b=l1.pop(0)
    c=l1.pop(0)
    if(a==b and b==c):
        if(n%3==0):
            print("YES")
        else:
            print("NO")
    else:
        x1=c-a
        x2=b-a
        if(x1+x2<=n):
            if((n-x1-x2)%3==0):
                print("YES")
            else:
                print("NO")
        else:
            print("NO")
    
