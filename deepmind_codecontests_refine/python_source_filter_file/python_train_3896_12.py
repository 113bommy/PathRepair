#Program Rook,Bishop,and King

def rook(sx,sy,lx,ly):
    if sx != lx or sy != ly:
        if sx == lx:
            move = 1
        if sy == ly:
            move = 1
        else:
            move = 2
    else:
        move = 0
    return move

def bishop(sx,sy,lx,ly):
    if sx != lx or sy != ly:
        if (sx+sy)%2 != (lx+ly)%2:
            move = 0
        else:
            if (sx+sy) == (lx+ly) or abs(sx-lx) == abs(sy-ly):
                move = 1
            else:
                move = 2
    else:
        move = 0
    return move

def king(sx,sy,lx,ly):
    move = 0
    if sx == lx:
        move = abs(sy-ly)
    elif sy == ly:
        move = abs(sx-lx)
    else:
        while sx != lx or sy != ly:
            if sx > lx:
                sx-=1
            elif sx < lx:
                sx+=1
            if sy > ly:
                sy-=1
            elif sy < ly:
                sy+=1
            move+=1
    return move

def main():
    p1,p2,p3,p4 = map(int,input().split())
    move = []
    move.append(rook(p1,p2,p3,p4))
    move.append(bishop(p1,p2,p3,p4))
    move.append(king(p1,p2,p3,p4))
    for x in move: print(x,end=" ")
main()
