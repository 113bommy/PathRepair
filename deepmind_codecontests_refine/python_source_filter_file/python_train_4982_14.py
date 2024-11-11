def main():
    import sys
    from array import array
    input = sys.stdin.readline

    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    dp_left = [array('I', [0] * K) for _ in range(N + 1)]
    dp_right = [array('I', [0] * K) for _ in range(N + 1)]
    dp_left[0][0] = 1
    dp_right[0][0] = 1
    for i, a in enumerate(A):
        for j in range(K):
            if dp_left[i][j]:
                dp_left[i + 1][j] = 1
                if j + a < K:
                    dp_left[i + 1][j + a] = 1
    for i, a in enumerate(reversed(A)):
        for j in range(K):
            if dp_right[i][j]:
                dp_right[i + 1][j] = 1
                if j + a < K:
                    dp_right[i + 1][j + a] = 1

    ok = N
    ng = -1
    mid = (ok+ng)//2
    while ok - ng > 1:
        a = A[mid]
        if a >= K:
            ok = mid
            mid = (ok+ng)//2
            continue
        flg = 0
        l = 0
        r = K-1
        while True:
            if dp_right[N-mid-1][r]:
                break
            r -= 1
        while True:
            if K-a <= l+r < K:
                flg = 1
                break
            elif l+r >= K:
                r -= 1
                if r < 0:
                    break
                while True:
                    if dp_right[N-mid-1][r]:
                        break
                    r -= 1
            else:
                l += 1
                if l >= K:
                    break
                while True:
                    if dp_left[mid][l]:
                        break
                    l += 1
                    if l >= K:
                        break
        if flg:
            ok = mid
        else:
            ng = mid
        mid = (ok+ng)//2
    print(ng+1)


if __name__ == '__main__':
    main()
