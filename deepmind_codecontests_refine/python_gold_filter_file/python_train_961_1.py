# fmt: off
FAST_IO = 1
if FAST_IO:
    import io, sys, atexit
    read = iter(sys.stdin.read().splitlines()).__next__
    _OUTPUT_BUFFER = io.StringIO()
    sys.stdout = _OUTPUT_BUFFER
    @atexit.register
    def write():
        sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
else:
    read = input
readint = lambda: int(read())
readlist = lambda: list(map(int, read().split()))


def solve(N, A):
    free = []
    ans = [10**6] * N
    low = 0
    for i in range(N):
        free.append(i)
        while free and low < A[i]:
            j = free.pop()
            if low != A[j]:
                ans[j] = low
                low += 1
            else:
                break
    return ans

N=readint()
A=readlist()
ans = solve(N,A)
if ans is None:
    print(-1)
else:
    print(' '.join(map(str, ans)))