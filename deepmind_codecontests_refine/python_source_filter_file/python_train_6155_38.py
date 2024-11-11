def main():

    n = int(input())
    coin = list(map(int, input().split()))

    if coin == [1, 1]:
        print("White")
        return

    if coin == [n, n]:
        print("Black")
        return


    white = max([coin[0] - 1, coin[1] - 1])
    black = max([n - coin[0], n - coin[0]])

    if white <= black:
        print("White")
    else:
        print("Black")


if __name__ == "__main__":
    main()