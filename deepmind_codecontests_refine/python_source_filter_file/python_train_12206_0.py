"""
codeforces 134A
"""


def moyenne():
    a = int(input())
    b = [int(x) for x in input().split()]
    z = sum(b)
    recup = [i + 1 for i, x in enumerate(b) if (z - x) // (a - 1) == x]
    return recup


def main():
    moy = moyenne()
    print(len(moy))
    print(*moy)


if __name__ == "__main__":
    main()
