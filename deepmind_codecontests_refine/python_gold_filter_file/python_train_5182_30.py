n,k=[int(x) for x in input().split()]
p=[int(x)-1 for x in input().split()]
c=[int(x) for x in input().split()]

ans=max(c)
if ans<0:
    print(ans)
    exit()

for i in range(n):
    #最後に自分という順番
    nxt=i
    lp=[]
    while 1:
        nxt=p[nxt]
        lp.append(nxt)
        if nxt==i:
            break
    lpc=sum(c[x] for x in lp)
    nxt=i
    lpl=len(lp)
    wks=0
    for j in range(lpl):
        nxt=p[nxt]
        wks+=c[nxt]
        ans=max(ans,(k-j-1)//lpl*max(0,lpc)+wks)
        if j==k-1:
            break
print(ans)
