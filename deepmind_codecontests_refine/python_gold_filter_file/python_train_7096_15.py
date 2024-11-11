import sys     
import math as mt
import bisect
#input=sys.stdin.readline
#t=int(input())
t=1
def ncr_util():
    inv[0]=inv[1]=1
    fact[0]=fact[1]=1
    for i in range(2,300001):
        inv[i]=(inv[i%p]*(p-p//i))%p
    for i in range(1,300001):
        inv[i]=(inv[i-1]*inv[i])%p
        fact[i]=(fact[i-1]*i)%p
#def solve():
    
    
    
    
for _ in range(t):
    #n=int(input())
    #n1=int(input())
    #s=input()
    #n=int(input())
    n,m=(map(int,input().split()))
    #n1=n
    #a=int(input())
    #b=int(input())
    #a,b,c,r=map(int,input().split())
    #x2,y2=map(int,input().split())
    #n=int(input())
    #s=input()
    #s1=input()
    #p=input()
    #l=list(map(int,input().split()))
    #l2=list(map(int,input().split()))
    #l=str(n)
    #l.sort(reverse=True)
    #l2.sort(reverse=True)
    #l1.sort(reverse=True)
    ans=[-1]*(n+1)
    l1=[]
    for i in range(m):
        x,y,z=(map(int,input().split()))
        if x==1:
            for i in range(y+1,z+1):
                ans[i]=0
        else:
            l1.append([y,z])
    flag=True
    ans[0]=1010
    #print(ans)
    for i in range(1,n+1):
        ans[i]+=ans[i-1]
    #print(ans,sorted(ans[5:7]))
    for i in range(len(l1)):
        if  ans[l1[i][0]:l1[i][1]+1]==sorted(ans[l1[i][0]:l1[i][1]+1]):
            flag=False
            break
    if flag:
        print("YES")
        print(*ans[1:])
    else:
        print("NO")
                
        