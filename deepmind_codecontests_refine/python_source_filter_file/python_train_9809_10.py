def solve():
    n,x=[int(v) for v in input().split()]
    s=input()
    cnt1=0
    cnt0=0
    ans=0
    tdiff=s.count('0')-s.count('1')
    foundx=False
    for i in range(n):
        if s[i]=='1':
            cnt1+=1
        else:
            cnt0+=1
        diff=cnt0-cnt1
        if x==diff:
            ans+=1
            foundx=True
        if tdiff>0 and (x-diff)%tdiff==0 and (x-diff)/tdiff>0:
            ans+=1
    if x==0:
        ans+=1
    if not tdiff:
        if foundx:
            print(-1)
        elif x==0:
            print(1)
        else:
            print(0)
    else:
        print(ans)
    

t=int(input())
for _ in range(t):
    solve()
