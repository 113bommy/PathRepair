def main():
    n = int(input())
    for i in range(n):
        w = input()
        print(w) if len(w) < 10 else print(w[:1] + str(len(w) - 2) + w[-1:])


if __name__ == "__main__":
    main()
