#Ashish Sagar
t=int(input())
for _ in range(t):
    n,s,k=map(int,input().split())
    #n=int(input())
    #s=list(input())
    l=list(map(int,input().split()))
    l.sort()    
    minn=0
    for i in range(s,n+1):
        if i not in l:
            minn=abs(i-s)
            break
    for i in range(s-1,0,-1):
        if i not in l:
            minn=min(minn,abs(i-s))
            break
    print(minn)    