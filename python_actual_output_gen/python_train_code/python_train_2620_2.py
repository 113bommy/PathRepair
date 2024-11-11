import sys
input = sys.stdin.buffer.readline

T = int(input())

for testcase in range(T):
    p,f = map(int,input().split())
    Cs,Cw = map(int,input().split())
    s,w = map(int,input().split())

    if s > w:
        s,w = w,s
        Cs,Cw = Cw,Cs
    
    res = 0

    for i in range(Cs+1):
        if i*s > p:
            break
        tmp = i

        pp = p-i*s
        Csc = Cs-i

        if Csc*s <= f:
            tmp += Csc
            ff = f-Csc*s
        else:
            tmp += f//s
            ff = f%s

        if Cw*w <= pp:
            tmp += Cw
        else:
            tmp += pp//w
            Cwc = (pp//w)*w
            if Cwc*w <= ff:
                tmp += Cwc
            else:
                tmp += ff//w
        res = max(res,tmp)

    print(res)