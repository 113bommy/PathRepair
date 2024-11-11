for testcases in range(int(input())):
    le=int(input())
    lis=list(map(int,input().split()))
    flag=0
    for i in range(len(lis)):
        if(lis[i]==1):
            flag=flag+1
        elif(lis[i]==0):
            continue
        else:
            flag=flag+1
            break
    if(flag%2==1):
        print("FIRST")
    else:
        print("SECOND")