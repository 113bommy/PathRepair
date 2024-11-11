import sys
import math
import bisect

def solve(A):
    B = []
    n = len(A)
    s = set(A)
    if len(s) == 1 and 0 in s:
        return None
    if sum(A) != 0:
        B.append([0, n - 1])
        return B
    val = 0
    for i in range(n):
        val += A[i]
        if val != 0:
            B.append([0, i])
            B.append([i+1,n-1])
        break
    return B

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = solve(A)
    if B == None:
        print('NO')
    else:
        print('YES')
        print(len(B))
        for i in range(len(B)):
            print(' '.join(list(str(a+1) for a in B[i])))

if __name__ == "__main__":
    main()
