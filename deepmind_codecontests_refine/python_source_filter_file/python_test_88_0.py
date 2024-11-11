for i in range(int(input())):
    n=int(input())
    li=list(map(int,input().split()))
    f=1 
    if(n%2!=0):
        for i in range(n-1):
            if(li[i]>li[i+1]):
                f=0 
                break 
    else:
        f=0
    if(f==1):
        print("NO")
    else:
        print("YES")
    