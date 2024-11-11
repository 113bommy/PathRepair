from sys import stdin, stdout
from collections import defaultdict
import math
from bisect import bisect_right

def main():
    t = int(stdin.readline())
    for _ in range(t):
        n,m,a,b = list(map(int, stdin.readline().split()))
        arr = list(map(int, stdin.readline().split()))
        arr.sort()
        max_crack = abs(a-b) - 1
        if a < b:
            max_sec = b - 1
        else:
            max_sec = n - b
        cnt = 0
        pos = bisect_right(arr, max_sec - 1) - 1
        while pos >= 0:
            if max_sec > arr[pos]:
                max_sec -= 1
                cnt += 1
            pos -= 1
        cnt = max(max_crack, cnt)
        stdout.write(str(cnt)+"\n")


main()