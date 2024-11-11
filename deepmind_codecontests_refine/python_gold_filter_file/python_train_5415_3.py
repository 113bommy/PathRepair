# -*- coding: utf-8 -*-

import sys


BOARD_SIZE_W = 8
BOARD_SIZE_H = 8


def set_queen(board, queen_point):
    """
    クイーンを指定座標に配置した後、残りの配置可能な位置の配列を返す
    """
    return filter(create_queen_filter(queen_point), board)


def create_queen_filter(queen_point):
    """
    指定位置にクイーンを配置したことにより、対象座標へ配置不可能にならないかを確認する関数を返す
    """

    def queen_filter(new_point):
        return new_point[1] != queen_point[1] and \
            new_point[0] != queen_point[0] and \
            new_point[0] != new_point[1] + queen_point[0] - queen_point[1] and \
            new_point[0] != -new_point[1] + queen_point[0] + queen_point[1]
    return queen_filter


def get_board_string(queen_points):
    """
    クイーンの位置座標の配列を指定出力形式に変換する
    """
    queen_points_set = set(list(map(lambda point: "{}:{}".format(point[1], point[0]), queen_points)))
    board_string_lines = []
    for y in range(BOARD_SIZE_H):
        line = ""
        for x in range(BOARD_SIZE_W):
            if "{}:{}".format(x, y) in queen_points_set:
                line += "Q"
            else:
                line += "."
        board_string_lines.append(line)
    return "\n".join(board_string_lines)


def get_all_queen_points(board, queen_points):
    if len(queen_points) >= 8:
        return queen_points
    elif not board:
        return []
    for empty_point in board:
        new_queen_points = [empty_point]
        new_queen_points.extend(queen_points)
        new_queen_points = get_all_queen_points(list(set_queen(board, empty_point)), new_queen_points)
        if new_queen_points:
            return get_all_queen_points(list(set_queen(board, empty_point)), new_queen_points)


def main():
    inputStr = sys.stdin.read()
    lines = inputStr.split("\n")
    lines = list(filter(lambda line: line, lines))
    if len(lines) <= 1:
        lines = []
    else:
        lines = lines[1:]
    queen_points = list(map(lambda line: list(map(int, line.split(" "))), lines))
    board = [[i % BOARD_SIZE_W, i // BOARD_SIZE_H] for i in range(BOARD_SIZE_H * BOARD_SIZE_W)]
    for queen_point in queen_points:
        board = list(set_queen(board, queen_point))
    sys.stdout.write(get_board_string(get_all_queen_points(board, queen_points)) + "\n")


if __name__ == '__main__':
    main()

