t=int(input())
while(t):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    if(n==1):
        print(0)
    else:
        s=0
        l1=l[:n]
        l2=l1[::-1]
        for i in range(k):
            s+=l2[i]
        print(l[-1]+s)
    t=t-1