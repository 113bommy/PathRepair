
import math
for j in range(int(input())):
    n,d = map(int,input().split())


    if d<=n:
        print('YES')
    else:
        l=1
        r=n
        h=0

        while l<=r:
            m = l +(r-l)//2

            if m+ math.ceil(d/(m+1))>n:
                r=m-1
            else:
                print('YES')
                h+=1
                break
            
            
        if h==0:
            print('NO')
