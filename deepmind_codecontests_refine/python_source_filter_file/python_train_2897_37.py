def main():
    n = int(input())
    a = [input() for _ in range(n)]
    ans = 0
    for j in range(n):
        f = True
        for i in range(n):
            for k in range(n):
                if a[(0+i)%n][(j+k)%n] != a[(0+k)%n][(j+i)%n]:
                    f = False
                    break
            if not f:
                break
        if f:
            ans += n
    print(ans)

if __name__ == "__main__":
    main()