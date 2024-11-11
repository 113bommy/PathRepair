import bisect
n = int(input().strip())
S = input().strip()
L=[[] for _ in range(26)]
for i,s in enumerate(S):
    L[ord(s)-ord("a")].append(i)

q = int(input().strip())
for _ in range(q):
    query=input().strip().split()
    if query[0]=="1":
        i=int(query[1])
        i-=1
        c=query[2]
        if S[i]!=c:
            delInd=bisect.bisect_left(L[ord(S[i])-ord("a")],i)
            del L[ord(S[i])-ord("a")][delInd]
            bisect.insort(L[ord(c)-ord("a")], i)
            S[i]=c
    else:
        l,r=map(int,[query[1],query[2]])
        l-=1; r-=1
        ans=0
        for j in range(26):
            ind=bisect.bisect_left(L[j],l)
            if ind<len(L[j]) and L[j][ind]<=r:
                ans+=1
        print(ans)