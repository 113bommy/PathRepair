t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    t1=n-1
    i=0
    flag=0
    if(n<3):
        print("NO")
    else:
        for i in range(n):
            if(a[i+2:].count(a[i])>=1):
                flag=1
    if(flag==1):
        print("YES")
    else:
        print("NO")
