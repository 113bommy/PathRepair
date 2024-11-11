import sys
import math
import bisect

def solve(A):
    n = len(A)
    d = dict()
    for a in A:
        if a not in d:
            d[a] = 0
        d[a] += 1
    B = []
    C = []
    for k in list(d.keys()):
        if d[k] == 1:
            B.append(k)
        elif d[k] >= 2:
            B.append(k)
            C.append(k)
    if len(B) and len(C) and B[-1] == C[-1]:
        C.pop()
    return B + C[::-1]

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = solve(A)
    print(len(B))
    print(' '.join(list(str(a) for a in B)))

if __name__ == "__main__":
    main()
