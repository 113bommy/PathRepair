def f(x):
    r = str(x)
    ans = 0
    for i in range(len(r)):
        ans += int(r[i])
    return not ans % 4


def main():
    a = int(input())
    for i in range(a, int(4 * len(str(a))) + 1):
        if f(i):
            print(i)
            return 0


main()
