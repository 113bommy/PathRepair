def solve(n):
    if n % 2 == 0:
        print("YES")
    else:
        print("NO")


def main():
    for i in range(int(input())):
        solve(int(input()))


if __name__ == "__main__":
    main()
