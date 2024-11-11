from  collections import defaultdict
for _ in range(int(input())):
    n,s,k=map(int,input().split())
    close=list(map(int,input().split()))
    out=10**10
    d=defaultdict(bool)
    for i in close:
        d[i]=True
    left=s
    right=s
    # print(d)
    while right<=n or left>0:
        # print(s,right,left)
        if left>0 and (not d[left]):
            out=abs(s-left)
            break
        if right<n and (not d[right]):
            out=abs(s-right)
            break
        left=left-1
        right=right+1
    print(out)