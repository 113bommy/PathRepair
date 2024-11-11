for _ in range(int(input())):
    i = int(input())
    t=[]
    for _ in range(i):
        c=list(map(int,input().split()))
        t.append([max(c[x+1]-x+1 for x in range(c[0])),c[0]])
    t.sort(key=lambda test:test[0])
    ans=pans=t[0][0]
    for x in t:
        if ans<=x[0]: pans+=(x[0]+1)-ans; ans+=(x[0]+1)-ans
        ans+=x[1]
    print(pans)