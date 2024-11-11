def main():
    x = int(input())
    if x == 3:
        print(5)
        return
    n = 1
    while True:
        if (n * n + 1) // 2 >= x:
            print(n)
            return
        n += 1

if __name__ == "__main__":
    main()