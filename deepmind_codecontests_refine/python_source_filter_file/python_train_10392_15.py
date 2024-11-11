def d_robot_arms(N, Pos):
    # 参考: http://drken1215.hatenablog.com/entry/2018/09/30/002900
    ans = []

    pos = []
    parity = (abs(Pos[0][0]) + abs(Pos[0][1])) % 2
    for x, y in Pos:
        parity_current = (abs(x) + abs(y)) % 2
        if parity != parity_current:
            return -1
        pos.append([x + y, x - y])

    d = []
    for i in range(30, -1, -1):
        d.append(1 << i)
    if parity % 2 == 0:
        d.append(1)
    ans.append(str(len(d)))
    ans.append(' '.join(list(map(str, d))))

    for i in range(N):
        xdir, ydir = 0, 0
        xsum, ysum = 0, 0
        tmp = []
        for j in range(len(d)):
            if xsum <= pos[i][0]:
                xdir = 1
                xsum += d[j]
            else:
                xdir = -1
                xsum -= d[j]
            
            if ysum <= pos[i][1]:
                ydir = 1
                ysum += d[j]
            else:
                ydir = -1
                ysum -= d[j]
            
            if xdir == 1 and ydir==1:
                tmp.append('R')
            elif xdir == 1 and ydir==-1:
                tmp.append('D')
            elif xdir == -1 and ydir==-1:
                tmp.append('L')
            else:
                tmp.append('U')
        ans.append(''.join(tmp))
    ans = '\n'.join(ans)
    return ans

N = int(input())
Pos = [[int(i) for i in input().split()] for j in range(N)]
print(d_robot_arms(N, Pos))