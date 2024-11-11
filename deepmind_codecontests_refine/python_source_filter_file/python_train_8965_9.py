import sys
import random

if __name__ == '__main__':
    q = int(sys.stdin.readline())
    for t in range(q):
        l1, r1, l2, r2 = (int(x) for x in sys.stdin.readline().split(' '))
        a = 0
        b = 0
        while a == b:
           a = random.randint(l1, r1 + 1)
           b = random.randint(l2, r2 + 1)
        print(a, b)