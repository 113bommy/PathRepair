for _ in range(int(input())):
    n=int(input())
    s=input().strip()
    ma=10**9
    mi=0
    for i in range(26):
        ch=chr(97+i)
        # print(ch)
        l=[]
        ans=[]
        for j in range(n):
            if s[j]!=ch:
                l.append(j)
                ans.append(s[j])
        # print(l)
        if ans[::-1]==ans:
            ma=0
            if len(ans)>=1:
                m=len(ans)+min(n-l[-1]-1,l[0])
                # print(l,m)
                for j in range(len(ans)-1):
                    m+=min(l[j+1]-l[j]-1,l[len(ans)-j-1]-l[len(ans)-j-2]-1)
                mi=max(mi,m)
    if ma==10**9:
        print(-1)
    else:
        print(n-mi)


