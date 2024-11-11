import sys

s1 = set((1, 2))


class Direction:
    __slots__ = ['left', 'top', 'down']

    def __init__(self, left, top, down):
        self.left = left
        self.top = top
        self.down = down


mydir = Direction(left=1, top=2, down=3)


def move(arr, i, j, dir, n):
    if j == n:
        if dir == mydir.left and i == 1:
            return True
        return False
    v = arr[i][j]
    if v in s1:
        # if left, move right
        if dir == mydir.left:
            return move(arr, i, j + 1, mydir.left, n)
    else:
        # if top
        if i == 0:
            # if left move down
            if dir == mydir.left:
                return move(arr, 1, j, mydir.top, n)
            # elif down move right
            elif dir == mydir.down:
                return move(arr, 0, j + 1, mydir.left, n)
        else:
            # if left, move up
            if dir == mydir.left:
                return move(arr, 0, j, mydir.down, n)
            # elif top move right
            elif dir == mydir.top:
                return move(arr, 1, j + 1, mydir.left, n)
    return False


def solution():
    input = sys.stdin.readline
    q = int(input())
    for i in range(q):
        n = int(input())
        arr1 = [int(x) for x in input().strip()]
        arr2 = [int(x) for x in input().strip()]
        arr3 = [arr1, arr2]
        try:
            out = move(arr3, 0, 0, 1, n)
            if out:
                print("YES")
            else:
                print("NO")
        except:
            print("NO")

    # print("\n".join(res))


if __name__ == "__main__":
    solution()
