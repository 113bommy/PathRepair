"""
import sys
sys.stdin = open('test.inp', 'r') 
sys.stdout = open('test.out', 'w')
"""
def sol():
    n=int(input())
    L=list(map(int,input().split()))
    L=[0]+L
    sum=0
    for i in range(1,n+1):
        sum=sum+L[i]
    if (sum*2) % (n*(n+1)) != 0:
        print("NO")
        return 
    sum=sum*2//(n*(n+1))
    res=[]

    cc=L[1]-L[n]
    cc=sum-cc
    if(cc<0 or cc%n != 0):
        print("NO")
        return
    res.append(cc//n)

    for i in range(2,n+1):
        cc=L[i]-L[i-1]
        cc=sum-cc
        
        if(cc<=0 or cc%n != 0):
            print("NO")
            return
        res.append(cc//n)
    
    print("YES")
    for i in res:
        print(i,end=" ")
    print("")
Test=int(input())
for i in range(1,Test+1):
    sol()