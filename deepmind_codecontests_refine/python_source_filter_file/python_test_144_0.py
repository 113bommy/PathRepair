import io, os
import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from heapq import heappush, heappop
from math import gcd, ceil, floor, factorial, sqrt
from itertools import combinations, permutations

input = sys.stdin.buffer.readline
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# input = sys.stdin.readline

def work():
    ans = 0 

    return 

# sys.setrecursionlimit(200010)
def main():
    test = int(input())

    for idt in range(test):
        n, m, k = map(int, input().split())
        big_p, small_p = (n + m - 1) // m, n // m 
        big_num = n - m * big_p + m 
        small_num = m - big_num
        # print("num", big_num, small_num)

        # if small_num == 0:
        #     # ans = [big_p] + list(range(1, n + 1))
        #     for _ in range(k):
        #         print(*ans, sep=" ")
        #     print()
        #     continue 
        
        # print("big_person", big_num * big_p)
        # print("small_person", small_num * small_p)
        h = []
        b = defaultdict(int)
        for i in range(1, n + 1):
            heappush(h, [0, i])
            b[i] = 0 

        for _ in range(k):
            small = []
            big = []
            for _ in range(big_p * big_num):
                _, pid = heappop(h)
                big.append(pid)
                b[pid] += 1 

            for _ in range(small_p * small_num):
                _, pid = heappop(h)
                small.append(pid)
            
            for i in range(0, len(small), small_p):
                print(small_p, end=" ")
                for j in range(i, i + small_p):
                    print(small[j], end=" ")
                print()

            for i in range(0, len(big), big_p):
                print(big_p, end=" ")
                for j in range(i, i + big_p):
                    print(big[j], end=" ")
                print()
        
            for i in range(1, n + 1):
                heappush(h, [b[i], i])
            #     print(b[i], end=" ")
            # print()
        print()
    return 

def main_jly():
    test = int(input())

    for idt in range(test):
        n, m, k = map(int, input().split())

        for i in range(k):
            idx = n % m * ((n + m - 1) // m) * i % n 
            for j in range(n % m):
                print((n + m - 1) // m, end=" ")
                for l in range((n + m - 1) // m):
                    print(idx + 1, end=" ")
                    idx = (idx + 1) % n 
                print()
            
            for j in range(m - n % m):
                print(n // m, end=" ")
                for l in range(n // m):
                    print(idx, end=" ")
                    idx = (idx + 1) % n 
                print()
        print()

if __name__ == '__main__':
    # main()
    main_jly()