from sys import stdin, gettrace

if not gettrace():
    def input():
        return next(stdin)[:-1]


def main():
    def solve():

        n,g,b = map(int, input().split())
        good=(n+1)//2
        cycles = (good -1)//g
        rem = good - cycles*g
        print(max(n, cycles*(g+b) + rem))

    q = int(input())
    for _ in range(q):
        solve()


if __name__ == "__main__":
    main()