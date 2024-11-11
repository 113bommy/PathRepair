from math import *
n,k=map(int,input().split())
if n*(n-1)//2<k:
    print("Impossible")
else:
    li=[]
    temp=int((-1+sqrt(8*k+1))//2)
    k-=(temp*(temp+1))//2
    li+=[temp]
    for i in range(temp):
        cur=temp-i
        if cur<=k and cur>0:
            li+=[cur]*(k//cur)
            k-=(k//cur)*cur
        if k==0 or cur==0:
            break
    li.reverse()
    num=li[0]
    ans=""
    for i in range(num+1):
        ans+="("
        n-=num+1
    ans+=")"
    for i in range(1,len(li)):
        num=li[i]-li[i-1]+1
        for j in range(num):
            ans+="("
        n-=num
        ans+=")"
    ans+=")"*li[-1]
    if n<0 or k>0:
        print("Impossible")
    else:
        for i in range(n):
            ans+="()"
            print(ans)
