import sys
import collections

def main():
    n = int(sys.stdin.readline())

    v = list(map(int, sys.stdin.readline().split()))
    ans = [0 for i in range(len(v))]

    best = -100000
    sum_odd = -100000
    sum_even = 0

    for i in range(len(v)):
        if(v[i]&1):
            best = max(best, sum_even + v[i])
            sum_odd, sum_even = max(max(sum_odd,v[i]), sum_even + v[i]), max(max(sum_even,0), sum_odd + v[i])
        else:
            best = max(best, sum_odd + v[i])
            sum_odd, sum_even = max(sum_odd, sum_odd + v[i]), max(max(sum_even,v[i]), sum_even + v[i])

    print(best)


if __name__ == "__main__":
    main()