import sys

def solve(a, b, chores):
    last = 0

    while a > 0:
        try:
            last = chores.pop()
            a -= 1
        except:
            print(0)
            return

    if len(chores) > 0:
        print(last - chores[-1])
    else:
        print(0)

if __name__ == '__main__':
    n, a, b = list(map(int, sys.stdin.readline().strip().split()))
    chores = set(list(map(int, sys.stdin.readline().strip().split())))
    chores = sorted(chores)
    solve(a, b, chores)