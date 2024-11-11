for _ in range(int(input())):
    n=int(input())
    q=input().split()
    ans=''
    flag=0
    for i in range(len(q)):
        if i and q[i][0]!=q[i-1][1]:
            ans+=q[i][0]
            ans+=q[i][0]
            flag=1
        else:
            ans+=q[i][0]
    ans+=q[-1][1]
    if not flag: ans+='a'
    print(ans)
