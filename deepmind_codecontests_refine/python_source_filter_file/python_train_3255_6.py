test=int(input())
for t in range(test):
    n=int(input())
    arr=input().split()
    b=sorted(arr)
    m=1000000007
    for i in range(n):
        if int(arr[i])<m:
            m=int(arr[i])
    flag=0
    for i in range(n):
        if int(arr[i])!=int(b[i]):
            if int(arr[i])%m!=0:
                flag=1

    if flag==0:
        print("YES")
    elif flag==1:
        print("NO")