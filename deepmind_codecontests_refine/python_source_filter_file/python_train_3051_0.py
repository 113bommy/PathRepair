from collections import Counter
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    d=Counter(a)
    dict={}
    for i in d:
        if d[i] in dict:
            dict[d[i]]+=1
        else:
            dict[d[i]]=1
    c=[d[i] for i in d]
    c=list(set(c))
    c.sort()
    ans=n
    s=len(set(a))
    for ele in range(len(c)):
        i=c[ele]
        tmp=dict[i]*i+(s-dict[i])*i
        s-=(dict[i]*i)
        ans=min(ans,n-tmp)
    print(ans)