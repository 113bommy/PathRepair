import sys
import math
# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

def main():
    a, b, c = map(int, input().split())
    d = b**2 - 4 * a * c
    x1 = (-b - math.sqrt(d)) / (2 * a)
    x2 = (-b + math.sqrt(d)) / (2 * a)
    if (x1 < x2):
        t = x1
        x1 = x2
        x2 = t
    print("{0:.10f}\n{1:.10f}".format(x1, x2))

main()