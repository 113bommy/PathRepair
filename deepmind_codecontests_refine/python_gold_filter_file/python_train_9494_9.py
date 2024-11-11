
t=int(input())
for _ in range(t):
    n=int(input())
    a,b,c=[int(x) for x in input().split()] #rps
    s=input()
    
    ans=[None for _ in range(n)]
    leftOvers=[]
    winCnts=0
    for i in range(n):
        if s[i]=='R':
            if b>0:
                b-=1
                ans[i]='P'
                winCnts+=1
            else:
                leftOvers.append(i)
        elif s[i]=='P':
            if c>0:
                c-=1
                ans[i]='S'
                winCnts+=1
            else:
                leftOvers.append(i)
        else:
            if a>0:
                a-=1
                ans[i]='R'
                winCnts+=1
            else:
                leftOvers.append(i)
    if winCnts*2>=n:
        print('Yes')
        for i in leftOvers:
            if a>0:
                ans[i]='R'
                a-=1
            elif b>0:
                ans[i]='P'
                b-=1
            else:
                ans[i]='S'
        print(''.join(ans))
    else:
        print('No')