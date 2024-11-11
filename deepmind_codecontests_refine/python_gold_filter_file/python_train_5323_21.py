import sys
#input=sys.stdin.buffer.readline
t=1   
mod=10**9+7
for __ in range(t):
    #a=[]
    n=int(input())
    #n,m=map(int,input().split())
    x=n
    maxi=0
    cnt=1
    while x>=7:
        x=x-7
        if x%4==0:
            maxi=cnt
        cnt+=1 
    if maxi>0:
        for i in range((n-maxi*7)//4):
            print(4,end="")
        for i in range(maxi):
            print(7,end="")
        print()
    else:
        if n%4==0:
            for i in range(n//4):
                print(4,end="")
        else:
            print(-1)