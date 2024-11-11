def main():
    n = int(input())
    a = list(map(int, input().split()))
    k = max(a)
    s = sum(a)
    print(max(k, (2*s + n - 1) // n))


if __name__ == "__main__":
    main()
