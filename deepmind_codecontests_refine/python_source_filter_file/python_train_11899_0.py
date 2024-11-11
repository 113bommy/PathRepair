import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    ar=list(map(int,input().split()))
    dic={}
    for i in range(1,n+1):
        dic[i]=0
    for i in ar:
        dic[i]+=1
    ans=0
    for i in range(1,n+1):
        coun=dic[i]
        if(coun>=3):
            ans+=((coun*(coun-1)*(coun-2))//6)
    for i in range(2,n):
        ans+=dic[i-1]*dic[i]*dic[i+1]
    for i in range(1,n):
        coun1=dic[i]
        coun2=dic[i+1]
        ans+=coun1*((coun2*(coun1-1))//2)
        ans+=coun2*((coun1*(coun1-1))//2)
    for i in range(1,n-1):
        coun1=dic[i]
        coun2=dic[i+2]
        ans+=coun1*((coun2*(coun1-1))//2)
        ans+=coun2*((coun1*(coun1-1))//2)
    print(ans)