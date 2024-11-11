t = int(input())
while t:
    n = int(input())
    a = list(map(int,input().split()))
    b = {}
    flag=0
    for i in range(n-1):
        if a[i] in b:
            b[a[i]]+=1
        else:
            b[a[i]]=1
    for i in b:
        if b[i]>1:
            flag=1
            break
    if flag==1:
        print("YES")
    else:
        print("NO")
    t-=1