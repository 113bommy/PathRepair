from collections import defaultdict
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def solve():
    S = input()[:-1]
    GX, GY = map(int, input().split())

    # 連続するFをまとめる ex.)FF->2
    # 連続するTをまとめる ex.)TTT->T
    S_parsed = []
    prev = S[0]
    seq = 1
    for c in S[1:]:
        if c == "F":
            if c == prev:
                seq += 1
            else:
                prev = c
                if seq % 2 == 0:
                    pass
                else:
                    S_parsed.append("T")
                seq = 1
        elif c == "T":
            if c == prev:
                seq += 1
            else:
                S_parsed.append(seq)
                seq = 1
            prev = c
    else:
        if S[-1] == "F":
            S_parsed.append(seq)

    # x,yを分離して考える
    x_move = []
    y_move = []

    dir_x = True
    for c in S_parsed:
        if c == "T":
            dir_x = not dir_x
        else:
            if dir_x:
                x_move.append(c)
            else:
                y_move.append(c)

    # x,y分けて、GX,GYに到達できるかをdpで判定
    dp_x = set()
    if len(x_move) > 0:
        if S[0] != "T":
            # Fから始まる場合は、正の方向からスタート
            dp_x.add(x_move[0])
        else:
            # TTから始まってたら、どっち方向からでもスタートできる
            dp_x.add(x_move[0])
            dp_x.add(-x_move[0])
    else:
        dp_x.add(0)

    for x in x_move[1:]:
        dp_x = {key+x for key in dp_x} | {key-y for key in dp_x}

    dp_y = set()
    if len(y_move) == 0:
        dp_y.add(0)
    else:
        dp_y.add(y_move[0])
        dp_y.add(-y_move[0])
    for y in y_move[1:]:
        dp_y = {key+y for key in dp_y} | {key-y for key in dp_y}

    if GX in dp_x and GY in dp_y:
        print("Yes")
    else:
        print("No")


solve()
