def main():
    M = int(input())
    DC = [list(map(int, input().split())) for _ in range(M)]
    S = 0
    cS = 0

    for d, c in DC:
        cS += c
        S += d*c

    ans = cS - 1 + (S-1)//9
    print(ans)

if __name__ == "__main__":
    main()
