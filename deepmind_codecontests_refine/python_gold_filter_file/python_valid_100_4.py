# Bad arrangements are those where the max-1 nos are before max
import sys
input = sys.stdin.buffer.readline

MOD = 998244353
def solve():
    A.sort()
    if A[N - 1] == A[N - 2]: # (1,1) -> (0,1) -> (0,0)
        return factorial[N]

    if A[N - 1] - A[N - 2] > 1: # (2,0) -> (1,0) -> X
        return 0
    
    k = 0 # count of max - 1 elements
    for a in A:
        if a == A[N - 2]:
            k += 1

    # N-k-1 elements can be arranged in any order in the N places: (N)p(N-k-1)
    # In the remaining k+1 elements if max is at the last: k!
    bad = factorial[k] * factorial[N] % MOD * pow(factorial[k + 1], MOD - 2, MOD) % MOD
    return (factorial[N] - bad) % MOD


def compute_factorials(N=int(1e6)):
    fact = [1] * (N + 1)
    for i in range(2, N + 1):
        fact[i] = fact[i - 1] * i % MOD
    return fact

factorial = compute_factorials()
test_cases = int(input())
for test_case in range(test_cases):
    N = int(input())
    A = list(map(int, input().split()))
    print(solve())