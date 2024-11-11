""" Created by Jieyi on 9/20/16. """


def block(board, w, h, direction, color):
    # horizontal.
    if direction == 0:
        for i in range(2):
            for j in range(4):
                board[h + i][w + j] = color
    # vertical.
    elif direction == 1:
        for i in range(2):
            for j in range(4):
                board[h + j][w + i] = color


def print_board(board):
    for i in range(len(board)):
        print(board[i])


def go_maze(board, s_w, s_h, g_w, g_h):
    place = board[s_h][s_w]
    if place == 0:
        return 'NG'
    w, h = s_w, s_h
    stack = []

    while True:
        board[h][w] = place + 1
        if h + 1 < len(board) and board[h + 1][w] == place:
            h += 1
            stack.append((w, h))
        elif w + 1 < len(board[h]) and board[h][w + 1] == place:
            w += 1
            stack.append((w, h))
        elif h - 1 > 0 and board[h - 1][w] == place:
            h -= 1
            stack.append((w, h))
        elif w - 1 > 0 and board[h][w - 1] == place:
            w -= 1
            stack.append((w, h))
        else:
            if len(stack) == 0 and board[h + 1][w] != place and board[h][w + 1] != place and board[h - 1][w] != place and board[h][w - 1] != place:
                return 'NG'
            (w, h) = stack.pop()

        if w == g_w and h == g_h:
            return 'OK'


def main():
    while True:
        w, h = map(int, input().split())
        if w == 0 and h == 0:
            break

        board = [[0 for _ in range(w)] for _ in range(h)]
        s_w, s_h = map(int, input().split())
        g_w, g_h = map(int, input().split())
        for _ in range(int(input())):
            color, direction, w, h = map(int, input().split())
            block(board, w, h, direction, color)

        # print_board(board)
        print(go_maze(board, s_w, s_h, g_w, g_h))


if __name__ == '__main__':
    main()