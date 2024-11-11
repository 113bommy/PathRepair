from sys import stdin

tt = int(stdin.readline())

for loop in range(tt):

    p,f = map(int,stdin.readline().split())
    cs,cw = map(int,stdin.readline().split())
    s,w = map(int,stdin.readline().split())

    if s > w:
        cs,cw = cw,cs
        s,w = w,s

    ans = 0
    for ps in range(cs+1):

        if ps * s > p:
            break

        pw = min(cw , (p-ps*s)//w)

        fs = min( cs-ps , f//s )
        fw = min( cs-pw , (f-fs*s)//w )
        ans = max(ans , ps+pw+fs+fw)

    print (ans)