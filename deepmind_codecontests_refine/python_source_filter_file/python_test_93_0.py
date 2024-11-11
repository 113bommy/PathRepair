t = int(input())


def solve(n, k):
    if k == 1:
        return n - 1
    h = (n - 1).bit_length()
    ans = h + ((n - (1 << h)) + k - 1) // (k - 1)
    return ans


for _ in range(t):
    n, k = map(int, input().split())
    print(solve(n, k))
