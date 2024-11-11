import io
import os

from collections import Counter, defaultdict, deque


def solve(A, B, C, D, X, Y, X1, Y1, X2, Y2):
    XOk = X1 <= X + B - A <= X2
    if X1 == X2:
        XOk = A == 0 and B == 0 and X == X1

    YOk = Y1 <= Y + D - C <= Y2
    if Y1 == Y2:
        YOk = C == 0 and D == 0 and Y == Y1

    if XOk and YOk:
        return "Yes"
    return "No"


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    T = int(input())
    for t in range(T):
        A, B, C, D = [int(x) for x in input().split()]
        X, Y, X1, Y1, X2, Y2 = [int(x) for x in input().split()]

        ans = solve(A, B, C, D, X, Y, X1, Y1, X2, Y2)
        print(ans)
