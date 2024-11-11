def main():
    N = int(input())
    F = tuple(map(int, input().split()))

    for i, b in enumerate(F):
        try:
            c = F.index(i+1)
        except ValueError:
            continue
        if b == c:
            print('YES')
            break
    else:
        print('NO')

main()
