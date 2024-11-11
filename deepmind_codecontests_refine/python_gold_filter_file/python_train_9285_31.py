def main():
    n = int(input())
    v = sorted(list(map(int, input().split())))
    a = sum(v[:n//2])
    b = sum(v[n//2:])
    print(a * a + b * b)


if __name__ == "__main__":
    main()
