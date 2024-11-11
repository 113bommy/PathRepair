import math
def dtb(n): 
    return bin(n).replace("0b","")
def btd(n): 
    return int(n,2) 
t=int(input())
for k in range(t):
    n=int(input())
    #a=list(map(int,input().split()))[:n]
    for i in range(n):
        print(i,end=" ")
    print()    
    