t=int(input())
for i in range(t):
    c=9999999999
    n=int(input())
    s=list(map(int,input().split()))
    d=[0]*(n+2)
    a=[]
    for j in range(n):
        if s[j] not in d:
            d[s[j]]=j
        else:
            a.append(j-d[s[j]]+1)
            d[s[j]]=j
    if len(a)==0:print(-1)
    else: print(min(a))