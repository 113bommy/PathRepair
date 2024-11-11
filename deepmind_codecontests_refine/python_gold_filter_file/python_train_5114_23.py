import sys


def docalc(ass):
    disturbed = [i for i in range(1, len(ass) - 1) if ass[i] == 0 and ass[i - 1] == 1 and ass[i + 1] == 1]
    if len(disturbed) == 0:
        return 0

    k = 1
    di = disturbed[0]
    for d in disturbed[1:]:
        if d - di > 2:
            k += 1
            di = d
    return k


def main():
    n = int(sys.stdin.readline())
    ass = [int(i) for i in sys.stdin.readline().split()]
    print(docalc(ass))


if __name__ == "__main__":
    main()
