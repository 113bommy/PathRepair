def main():
    P, Y = map(int, input().split())

    y = Y if Y % 2 else Y - 1
    for i in range(y, P, -2):
        p = min(P + 1, int(i ** 0.5))
        for j in range(3, p, 2):
            if not i % j:
                break
        else:
            print(i)
            break
    else:
        print(-1)

main()
