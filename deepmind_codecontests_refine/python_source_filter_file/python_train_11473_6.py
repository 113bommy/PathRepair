import math
t=input()
for i in range(0,int(t)):
    a,b=map(int,input().split())
    if int(math.gcd(a,b))==1:
        print("Infinite")
    else:
        print("Finite")