def main():
    L, R, X, Y, K = map(int, input().split())

    for i in range(X, Y + 1):
        if L <= i * K <= R:
            ans = 'YES'
            break
    else:
        ans = 'NO'

    print(ans)

main()
