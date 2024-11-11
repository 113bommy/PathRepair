def solve(N, G, B):
    threshold = (N + 1) // 2
    cycles, remainder = divmod(threshold, G)
    if cycles == 0:
        return N
    if remainder == 0:
        remainder -= B
    return max(N, cycles * (G + B) + remainder)


if __name__ == "__main__":
    T, = map(int, input().split())
    for t in range(T):
        N, G, B = map(int, input().split())
        ans = solve(N, G, B)
        print(ans)
