n=int(input())
import math
for i in range(n):
    n,x,y,d=map(int,input().split())
    if (y-x)%d==0:
        print((y-x)//d)
    else:
        if (y-1)%d !=0 and (n-y)%d!=0:
            print(-1)
        elif (y-1)%d!=0 and (n-y)%d==0:
            print(abs((n-y)//d +(n-x)//d+1))
        elif (y-1)%d==0 and (n-y)%d!=0:
            print(abs((x-1)//d +(y-1)//d+1))
        else:
            print(min(abs(math.ceil(((n-y)/d)) +math.ceil((n-x)/d)),abs(math.ceil(((x-1)/d)) +math.ceil((y-1)/d))))