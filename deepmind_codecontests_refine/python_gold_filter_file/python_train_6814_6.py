from math import ceil, log10


def main():
    a = int(input())

    n = ceil(log10(a)) + 1
    x = (45*n*10**(n-1)+1)%a
    print(a-x+1, 10**n+a-x)


if __name__ == '__main__':
    main()

