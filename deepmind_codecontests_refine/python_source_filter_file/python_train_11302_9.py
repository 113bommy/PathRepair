from math import *

black_pieces = int(input())
black_pieces_list = []
king_pos = input().split()
king_pos[0], king_pos[1] = int(king_pos[1]), int(king_pos[0])

xp, xn, yp, yn = -1, -1, -1, -1
xpyp, xnyp, xpyn, xnyn = -1, -1, -1, -1

xp_dis, xn_dis, yp_dis, yn_dis = 0, 0, 0, 0
xpyp_dis, xnyp_dis, xpyn_dis, xnyn_dis = 0, 0, 0, 0

def distance(x, y):
    dis = (x ** 2) + (y ** 2)
    return dis

i = 0
while (i < black_pieces):
    piece = input().split()
    black_pieces_list.append(piece)
    x, y = int(piece[2]), int(piece[1])
    x-=king_pos[0]
    y-=king_pos[1]
    dis = distance(x, y)
    if (y == 0 and x > 0):
        if (xp == -1):
            xp_dis = dis;
            xp = i
        elif (xp != -1 and dis < xp_dis):
            xp_dis = dis;
            xp = i
    elif (y == 0 and x < 0):
        if (xp == -1):
            xn_dis = dis;
            xn = i
        elif (xn != -1 and dis < xn_dis):
            xn_dis = dis;
            xn = i
    elif (y < 0 and x == 0):
        if (yp == -1):
            yp_dis = dis;
            yp = i
        elif (yp != -1 and dis < yp_dis):
            yp_dis = dis;
            yp = i
    elif (y > 0 and x == 0):
        if (yn == -1):
            yn_dis = dis;
            yn = i
        elif (yn != -1 and dis < yn_dis):
            yn_dis = dis;
            yn = i
    elif (abs(y / x) == 1 and x > 0 and y < 0):
        if (xpyp == -1):
            xpyp_dis = dis;
            xpyp = i
        elif (xpyp != -1 and dis < xpyp_dis):
            xpyp_dis = dis;
            xpyp = i
    elif (abs(y / x) == 1 and x < 0 and y < 0):
        if (xnyp == -1):
            xnyp_dis = dis;
            xnyp = i
        elif (xnyp != -1 and dis < xnyp_dis):
            xnyp_dis = dis;
            xnyp = i
    elif (abs(y / x) == 1 and x > 0 and y < 0):
        if (xpyn == -1):
            xpyn_dis = dis;
            xpyn = i
        elif (xpyn != -1 and dis < xpyn_dis):
            xpyn_dis = dis;
            xpyn = i
    elif (abs(y / x) == 1 and x < 0 and y > 0):
        if (xnyn == -1):
            xnyn_dis = dis;
            xnyn = i
        elif (xnyn != -1 and dis < xnyn_dis):
            xnyn_dis = dis;
            xnyn = i
    i += 1

king_in_check = 0
if (xp != -1 and (black_pieces_list[xp][0] == "R" or black_pieces_list[xp][0] == "Q")):
    king_in_check += 1
elif (xn != -1 and (black_pieces_list[xn][0] == "R" or black_pieces_list[xn][0] == "Q")):
    king_in_check += 1
elif (yp != -1 and (black_pieces_list[yp][0] == "R" or black_pieces_list[yp][0] == "Q")):
    king_in_check += 1
elif (yn != -1 and (black_pieces_list[yn][0] == "R" or black_pieces_list[yn][0] == "Q")):
    king_in_check += 1
elif (xpyp != -1 and (black_pieces_list[xpyp][0] == "Q" or black_pieces_list[xpyp][0] == "B")):
    king_in_check += 1
elif (xpyn != -1 and (black_pieces_list[xpyn][0] == "Q" or black_pieces_list[xpyn][0] == "B")):
    king_in_check += 1
elif (xnyp != -1 and (black_pieces_list[xnyp][0] == "Q" or black_pieces_list[xnyp][0] == "B")):
    king_in_check += 1
elif (xnyn != -1 and (black_pieces_list[xnyn][0] == "Q" or black_pieces_list[xnyn][0] == "B")):
    king_in_check += 1

if (king_in_check > 0):
    print("YES")
else:
    print("NO")