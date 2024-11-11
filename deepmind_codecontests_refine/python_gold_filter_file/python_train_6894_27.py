from sys import stdin


def main():
    r = stdin.readline
    cases = int(r())
    for case in range(cases):
        a, b = map(int, r().strip().split())
        print("NO" if a%b!=0 else "YES")


main()