from sys import stdin
readline = stdin.readline


from itertools import product
from operator import itemgetter
from math import isinf


def scrap_top_left(picture):
    for py, px in product(range(len(picture)), repeat=2):
        if picture[py][px] != -1:
            return px, py


def is_match(window, picture, wx, wy):
    for py, px in product(range(len(picture)), repeat=2):
        if picture[py][px] == -1:
            continue
        if window[wy + py][wx + px] != picture[py][px]:
            return False
    return True


def search(window, picture):
    for wy, wx in product(range(len(window) - len(picture) + 1), repeat=2):
        if is_match(window, picture, wx, wy):
            px, py = scrap_top_left(picture)
            return wx + px + 1, wy + py + 1
    return float('inf'), float('inf')


# http://d.hatena.ne.jp/odz/20070622/1182497414
def rotate_clockwise(matrix):
    return [list(row) for row in zip(*reversed(matrix))]


while True:
    window_size, picture_size = map(int, readline().split())
    if window_size == 0:
        break
    window = [list(map(int, readline().split())) for _ in range(window_size)]
    picture = [list(map(int, readline().split())) for _ in range(picture_size)]
    top_left = []
    for _ in range(4):
        top_left.append(search(window, picture))
        picture = rotate_clockwise(picture)
    top_left = min(top_left, key=itemgetter(1, 0))
    if isinf(top_left[0]):
        print('NA')
    else:
        print(*top_left)