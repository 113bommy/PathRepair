#import math,statistics,random

# write any random term of infinite set and simplify it you will get a
# general term i.e. a**(max power of a possible) + b*(function of a).
# so to achieve n if we can go from n to 1 backwards then n is in the set.
# so we can subtract b till it gets 0 and then divide by a till it becomes 1.But
# this will give us TLE.
# so we will first subtract by a then check if its divisible by b. if not then 
# subtract by a**2/a**3/a**4,...,etc till it does not get divisible by b.
# as we are subtracting by exponetial elements it will take much less time.
# but for a==1 we do it seperately as in that case remainder=1(always)

def void():
    n,a,b=map(int,input().split())
    if a==1:
        if (n-1)%b==0:
            print("Yes")
        else:
            print("No")
    else:
        i=1
        valid=False
        while i<=n:
            if (n-i)%b==0:
                valid=True
                break
            i*=a
        if valid:
            print("Yes")
        else:
            print("No")
        
for i in range(int(input())):
    void()
