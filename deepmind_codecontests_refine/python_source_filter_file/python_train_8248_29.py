import sys,math
input=sys.stdin.readline
t=int(input())
for r in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    d1 = {}
    for i in l:
        try:
            d1[i]+=1
        except:
            d1[i]=1
    maxi = max(l)
    ans = 0
    for i in range(1,maxi+1):
        temp = []
        for j in l:
            temp.append(j^i)
        d2 = {}
        for j in temp:
            try:
                d2[j]+=1
            except:
                d2[j]=1
        if d1 == d2:
            ans = i
            break
    if ans == 0:
        print(-1)
    else:
        print(ans)

