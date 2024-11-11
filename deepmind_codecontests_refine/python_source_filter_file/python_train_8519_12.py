import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(readline())
A = sorted(map(int, readline().split()))

def main(A):
    N = len(A)
    if A[0] == A[-1]:
        x = A[0]
        return x == N - 1 or 2 * x <= N
    if A[0] + 1 != A[-1]:
        return False
    a, b = A[0], A[-1]
    full = b
    unique = A.count(a)
    people, color = N - unique, A[-1] - unique
    return color > 1 and 2 * color <= people

print('Yes' if main(A) else 'No')