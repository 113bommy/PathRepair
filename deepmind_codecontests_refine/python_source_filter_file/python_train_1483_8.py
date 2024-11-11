def main():
    N, M = [int(x) for x in input().split()]
    L = [int(x) for x in input().split()]

    if sum(L) < N or any(map(lambda e: e[1] > N-e[0], enumerate(L))):
        print(-1)
        return

    S = [i+1 for i in range(M)]
    S[M-1] = N - L[M-1]
    for i in reversed(range(M-1)):
        S[i] = max(S[i], S[i+1] - L[i])

    print(" ".join(map(lambda s: str(s), S)))
    return


if __name__ == '__main__':
    main()