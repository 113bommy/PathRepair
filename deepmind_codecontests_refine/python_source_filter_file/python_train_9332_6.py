def main():
    N, M = map(int, input().split())
    A = tuple(map(int, input().split()))
    B = tuple(map(int, input().split()))

    ans = []
    apnd = ans.append
    for i in A:
        n = -float('inf')
        for j in B:
            n = max(n, i * j)
        apnd(n)

    print(min(max(ans[1:]), max(ans[:-1])))

main()
