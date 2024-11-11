import sys
input=sys.stdin.readline
t=int(input())
while t:
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    i=0
    j=n*k
    if(n%2):
        ii=n//2
        jj=n//2+1
    else:
        ii=n//2-1
        jj=n//2+1
    su=0
    while j-i>1:
        i=i+ii
        j=j-jj
        su+=l[j]
        #print(l[j])
    print(su)
    t-=1