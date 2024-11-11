for _ in range(int(input())):
    n=int(input())
    s=input()
    cc=97
    ans=0
    while(cc<123):
        c = chr(cc)
        i=0
        j=n-1
        tmp=0
        while(i<j):
            if s[i]==s[j]:
                tmp+=2
                i+=1
                j-=1
                continue
            if s[i]==c:
                i+=1
                continue
            if s[j]==c:
                j-=1
                continue
            tmp=0
            break
        if i==j:
            tmp+=1
        ans = max(ans, tmp)
        # print(tmp, c)
        cc+=1
    if ans<2:
        print(-1)
    else:
        print(n-ans)