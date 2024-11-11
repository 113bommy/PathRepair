def main():
    L, R, X, Y, K = map(int, input().split())

    for i in range(L, R + 1):
        if X <= i * K <= Y:
            ans = 'YES'
            break
    else:
        ans = 'NO'

    print(ans)

main()
