from sys import stdin, stdout
import sys

#brutal search

if __name__ == '__main__':
    fa = list(map(int, stdin.readline().split()))
    x0 = fa[0]
    y0 = fa[1]
    ax = fa[2]
    ay = fa[3]
    bx = fa[4]
    by = fa[5]

    sa = list(map(int, stdin.readline().split()))
    xs = sa[0]
    ys = sa[1]
    t = sa[2]

    dis = []
    cx = x0
    cy = y0
    px = x0
    py = y0
    disSum = 0

    for i in range(30):
        disSum += abs(cx-px) + abs(cy-py)

        la = [cx, cy, disSum]
        dis.append(la)

        nx = ax * cx + bx
        ny = ay * cy + by

        px = cx
        py = cy

        cx = nx
        cy = ny

    res = 0
    #brutal
    #print(dis)
    for i in range(30):
        for j in range(i, 30):
            for k in range(i, j+1):
                #op1  2*(i,k) + k,j
                #print(i)
                #print(j)
                #print(k)

                op1 = 2*(dis[k][2] - dis[i][2]) + (dis[j][2] - dis[k][2])

                #op2  i,k + 2*(k,j)
                op2 = (dis[k][2] - dis[i][2]) + 2*(dis[j][2] - dis[k][2])

                ttldis = abs(xs-dis[k][0]) + abs(ys-dis[k][1]) + min(op1, op2)

                if t >= ttldis:
                    res = max(res, j-i+1)

    print(str(res))
