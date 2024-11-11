import sys
import math
import bisect

def solve(A):
    n = len(A)
    m = len(A[0])
    '''
    for i in range(n):
        print('A[%d]: %s' % (i, A[i]))
    '''
    min_x = n - 1
    max_x = 0
    min_y = n - 1
    max_y = 0
    for i in range(n):
        for j in range(m):
            if A[i][j] == '*':
                min_x = min(min_x, i)
                max_x = max(max_x, i)
                min_y = min(min_y, j)
                max_y = max(max_y, j)
    #print('min_x: %d, max_x: %d, min_y: %d, max_y: %d' % (min_x, max_x, min_y, max_y))
    B = []
    for i in range(min_x, max_x + 1):
        B.append(A[i][min_y:max_y+1])
    return B

def main():
    n, m = map(int, input().split())
    A = []
    for i in range(n):
        A.append(input())
    B = solve(A)
    for t in B:
        print(t)

if __name__ == "__main__":
    main()
