N, M, Q, *ABCD = map(int, open(0).read().split())

L = list(zip(*[iter(ABCD)] * 4))

def solve(A):
    if len(A) == N:
        return sum(d for a, b, c, d in L if A[b - 1] - A[a - 1] == c)

    return max(solve(A + [i]) for i in range(A[-1], M + 1))

print(solve([1]))