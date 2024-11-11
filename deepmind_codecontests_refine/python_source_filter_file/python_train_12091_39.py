from math import sqrt
import heapq


def main():


    n,m,k = [int(x) for x in input().split(' ')]
    a = [int(x) for x in input().split(' ')]

    a = sorted(a)

    ans = ((k*a[-1] + a[-2])* m //(k+1)) + (a[-1]* (m%(k+1)))
    print(ans)

if __name__ == '__main__':
    main()

