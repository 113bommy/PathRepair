def main():
    X, Y = map(int, input().split())

    if not X % Y:
        print(-1)
    else:
        print(X)

main()
