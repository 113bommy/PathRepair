t=int(input())
for tt in range(t):
    n=int(input())
    s=str(n)
    ans=0
    res=[]
    for i in range(len(s)):
        if i==len(s)-1 and s[i]!="0":
            res.append(s[i])
            ans+=1
        elif s[i]!='0':
            ans+=1
            res.append((10**(len(s)-i-1))*int(s[i]))
    print(ans)
    for ii in res:
        print(ii,end=" ")
    print()