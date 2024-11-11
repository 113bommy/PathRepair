import sys
input=sys.stdin.readline
n=int(input())
l=input()
q=int(input())
kl=tuple(map(int,input().split()))
for i in kl:
    k=i
    d=0
    m=0
    dm=0
    ans=0
    for j in range(n):
        if l[j]=='D':
            d+=1
        elif l[j]=='M':
            m+=1
            dm+=d
        elif l[j]=='C':
            ans+=dm
        if j>=k-1:
            if l[j-k+1]=='D':
                dm-=m
                d-=1
            elif l[j-k+1]=='M':
                m-=1
    print(ans)
