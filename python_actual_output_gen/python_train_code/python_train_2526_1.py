try:
    for t in range(int(input())):
        n=int(input())
        if 2<=n<=50000:
            l=[int(x) for x in input().split()][:n]
            ans="NO"
            for i in range(1,len(l)):
                if l[i-1]<l[i]:
                    ans="YES"
                    break
            print(ans)





except:
    pass