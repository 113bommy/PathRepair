# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def solve():
    N = int(input())
    A = list(map(int, input().split()))

    k = sum(A)//(N*(N+1)//2)
    if sum(A) % (N*(N+1)//2) != 0 or True:
        return "NO"

    D = [0]*N
    for i in range(N-1):
        D[i] = A[i+1]-A[i]-k
    D[-1] = A[0]-A[-1]-k

    cnt = sum([v//N for v in D])
    if all(x <= 0 and -x % N == 0 for x in D)and -cnt == k:
        return "YES"
    else:
        return "NO"


print(solve())
