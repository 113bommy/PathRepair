import sys
input=sys.stdin.readline
n=int(input())
l=input().split()
li=[int(i) for i in l]
maxa=-10**9
for i in range(-32,32):
    l=[]
    for j in range(n):
        if(li[j]<=i):
            l.append(li[j])
        else:
            if(l==[]):
                continue
            dp=[0 for ok in range(len(l))]
            dp[0]=l[0]
            for k in range(1,len(l)):
                dp[k]=max(dp[k-1]+l[k],l[k])
            z=max(dp)
            maxa=max(z-i,maxa)
            l=[]
    if(l!=[]):
        dp=[0 for ok in range(len(l))]
        dp[0]=l[0]
        for k in range(1,len(l)):
            dp[k]=max(dp[k-1]+l[k],l[k])
            z=max(dp)
            maxa=max(z-i,maxa)
        l=[]
print(maxa)
