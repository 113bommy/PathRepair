
import math as m
import itertools as itr
import sys

from math import ceil
def main():
    for _ in range(int(input())):
        a, b, c, d = map(int, input().split())
        if a > b and c <= d:
            print(-1)
        elif a <= b:
            print(b)
        else:
            print(b + c * ceil((a - b) / (c - d)))

            
            
if __name__ == '__main__':
    main()








