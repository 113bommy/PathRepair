from sys import stdin, gettrace

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def main():
    ss = input()
    n = len(ss)
    print(3)
    print("L", n-1)
    print("R", n-1)
    print("R", 2*n-1)


if __name__ == "__main__":
    main()
