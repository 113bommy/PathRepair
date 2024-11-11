t=int(input())
import sys
input=sys.stdin.readline
while t>0:
    t-=1
    n,r=map(int,input().split())
    a=[int(x) for x in input().split()]
    a.sort(reverse=True)
    d={}
    i=0;j=0
    while i<n:
        if a[i] not in d:
            d[a[i]]=[i]
        j=i+1
        while j<n and a[j]==a[j-1]:
            j+=1
        if j==n:   
            d[a[j-1]].append(j)
        else:    
            d[a[j-1]].append(j-1)
        i=j
    i=0;c=0
    while i<n:
        a[i]=a[i]-c*r
        dt=c
        if a[i]>=0:
            c+=1
        
        i=d[a[i]+dt*r][1]+1

    print(c)   