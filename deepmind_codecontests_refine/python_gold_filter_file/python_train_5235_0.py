t=int(input())
for _ in range(t):
    n,k=[int(x) for x in input().split()]
    a=[int(x) for x in input().split()]
    if(k==0):
        print(max(a)-min(a))
    elif(k>=n-1):
        s=sum(a)
        print(s)
    else:
        a.sort()
        s=0
        for i in range(k+1):
            s+=a[-1-i]
        print(s)