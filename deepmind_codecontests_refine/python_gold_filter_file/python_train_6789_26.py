from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    T = int(input())
    for _ in [0] * T:
        A, B = map(int, input().split())
        n = 0
        for i in range(1, len(str(B)) + 1):
            b = int('9' * i)
            if b <= B:
                n += 1
        ans = A * n
        print(ans)


main()
