import math
def dtb(n): 
    return bin(n).replace("0b","")
def btd(n): 
    return int(n,2) 
t=int(input())
for k in range(t):
    n=int(input())
    #a=list(map(int,input().split()))[:n]
    if n<=30:
        print("NO")
    else:
        print("YES")
        a=[6,10,14]
        if(n-6-10-14) in a:
            print(6,10,15,(n-6-10-15))
            continue
        print(6,10,14,(n-6-10-14))
    