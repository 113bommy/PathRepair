def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        x = (n - 1) / 2
        print(8 * ((x * (x + 1) * n) / 6))

if __name__ == "__main__":
    main()