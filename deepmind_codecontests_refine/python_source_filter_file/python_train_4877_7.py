def main():
    import sys
    from collections import defaultdict
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    C = defaultdict(int)
    for a in A:
        C[a] += 1

    ans = 0
    for i in range(2, 10**5+1):
        ans = max(ans, C[i-1] + C[i] + C[i+1])
    print(ans)


if __name__ == '__main__':
    main()
