
import math
t=int(input())
for _ in range(t):
    x=int(input())
    flag=1
    if x<3:
        print("0")
        flag=0
    else:
        a = 3
        b = 1
        ans=0
        while x>=2:
            c = -(2*x)
            d = (b**2) - (4*a*c)
            s1 = int((-b-math.sqrt(d))/(2*a))
            s2 = int((-b+math.sqrt(d))/(2*a))
            #print(s1,s2)
            if s1>0:
                ans+=1
                mi=int((s1*(3*s1+1))/2)
                x-=mi
            else:
                ans+=1
                mi = int((s2*(3 * s2 + 1)) / 2)
                x-=mi
    if flag==1:
        print(ans)

