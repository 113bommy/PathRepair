from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    T = int(input())
    for _ in [0] * T:
        N, D = map(int, input().split())
        for x in range(100000):
            if x + (D + x) // (x + 1) <= N:
                print('YES')
                break
        else:
            print('NO')


main()
