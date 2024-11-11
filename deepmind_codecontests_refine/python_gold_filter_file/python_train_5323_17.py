import math
def main():
    n = int(input())
    a = math.inf
    for i in range(0, n//7 + 1):
        if (n - 7*i)/4 % 1 == 0:
            a = min(a, (n - 7*i)//4)
    if a == math.inf:
        print(-1)
    else:
        y = []
        b = (n - 4*a)//7
        for i in range(a):
            y.append(4)
        for j in range(b):
            y.append(7)
        print(''.join(map(str, y)))


if __name__ == '__main__':
    main()