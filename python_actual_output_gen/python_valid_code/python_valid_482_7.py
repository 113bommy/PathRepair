for _ in range(int(input())):
    n=int(input())
    l=list(map(str, input().split()))
    # print(l)
    flag=False
    ans=""
    j=0
    for i in range(n-2):
        if i==0:
            ans+=l[i]
        else:
            if ans[i]==l[i][0]:
                ans+=l[i][1]
            else:
                ans+=l[i]
                j+=1
                flag=True
        j+=1
    
    if flag==False:
        ans+='a'
    print(ans)