for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    ans=0
    flag=1
    for i in range(n):
        if(i+1!=arr[i]):
            if(flag):
                ans+=1
                flag=0
        else:
            flag=1
    print(min(2,ans))
                