def main():
    n=int(input())
    s=[input() for _ in [0]*n]
    def check(a):
        for i in range(n):
            for j in range(i):
                if s[i%n][(j+a)%n]!=s[(j+a)%n][i%n]:
                    return 0
        return 1
    print(n*sum([check(i) for i in range(n)]))
main()