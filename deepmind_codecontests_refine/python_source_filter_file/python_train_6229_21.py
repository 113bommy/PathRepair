#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10 ** 8)
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

A, B = map(int, readline().split())
color_flipped = False
if A < B:
    A, B = B, A
    color_flipped = True


def solve():
    hb = min(B, 12)
    h = (hb * 2 + 1) * 3
    w = 100
    # If not flipped, False -> White (A), True -> Black (B)
    grid = [[True] * w for _ in range(h)]
    black = 1
    white = 0
    for i in range(hb):
        if black == B:
            break
        black += 1
        white += 1
        for c in range(w):
            for j in range(3):
                grid[6 * i + j + 3][c] = False

    def paint_white(i):
        nonlocal white
        for c in range(0, w, 2):
            if white == A:
                return
            grid[6 * i + 1][c] = False
            white += 1

    def paint_black(i):
        nonlocal black
        for c in range(0, w, 2):
            if black == B:
                return
            grid[6 * i + 4][c] = True
            black += 1

    for i in range(hb):
        paint_white(i)
        paint_black(i)
    assert black == B
    while white < A:
        grid.append([True] * w)
        grid.append([True] * 2)
        for c in range(0, w, 2):
            if white == A:
                break
            white += 1
            grid[-1][c] = False

    return grid


def print_grid(grid):
    h, w = len(grid), len(grid[0])
    print(h, w)
    for r in range(h):
        for c in range(w):
            if grid[r][c] ^ color_flipped:
                print("#", end="")
            else:
                print(".", end="")
        print()


if __name__ == "__main__":
    print_grid(solve())
