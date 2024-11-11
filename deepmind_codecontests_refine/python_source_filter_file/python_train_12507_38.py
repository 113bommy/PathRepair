import sys
import math
import bisect

def main():
    n = int(input())
    A = []
    for i in range(n):
        A.append(list(map(int, input().split())))
    k = int(input())
    ans = 0
    for i in range(n):
        if k - 1 <= A[i][1]:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()
