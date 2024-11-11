import sys

def solve():
    input = sys.stdin.readline
    N, M, V, P = map(int, input().split())
    A = [int(a) for a in input().split()]
    A.sort()
    B = A[N - P]
    low, high = -1, N
    while high - low > 1:
        mid = (low + high) // 2
        if mid >= N - P: high = mid
        elif A[mid] + M < B: low = mid
        else:
            border = A[mid] + M
            room = 0
            for i in range(N - P):
                if i != mid: room += min(M, max(0, border - A[i]))
            if room >= max(0, V - P) * M: high = mid
            else: low = mid
            #print(mid, room)
    print(N - high)

    return 0

if __name__ == "__main__":
    solve()