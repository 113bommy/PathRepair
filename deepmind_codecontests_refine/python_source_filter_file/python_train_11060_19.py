import math

for _ in range(int(input())):
    n=int(input())
    if (n//2)%2==1:
        print("NO")
    else:
        print("YES")
        d=[]
        for i in range(1,n//2+1):
            d.append(2*i)
        for i in range(1,n//2+1):
            d.append(2*i-1)
        d[-1]+=2
        print(*d)
    