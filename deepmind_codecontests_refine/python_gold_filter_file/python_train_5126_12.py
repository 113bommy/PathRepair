for test in range(int(input())):
    n,x=map(int,input().split())
    ans=list(map(int,input().split()))
    ans=list(set(ans))
    ans.sort()
    flag=0
    for i in range(len(ans)-1,-1,-1):
        ele=ans[i]
        temp=ele-i-1
        if x-temp>=0:
            flag=1
            print(ele+x-temp)
            break
    if flag==0:
        print(x)
    

