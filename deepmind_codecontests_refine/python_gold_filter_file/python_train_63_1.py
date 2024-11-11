import itertools
from collections import defaultdict
from math import gcd


def main():
    n, k = [int(v) for v in input().split()]
    data = [int(v) for v in input().split()]
    print(min([k//d for d  in data if k%d==0]))


if __name__ == "__main__":
    main()
