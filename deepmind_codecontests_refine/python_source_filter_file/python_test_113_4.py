def main():
    for _ in range(int(input())):
        a, p1 = map(int, input().split())
        b, p2 = map(int, input().split())

        p1, p2 = p1 - min(p1, p2), p2 - min(p1, p2)

        a, b = str(a), str(b)

        if p1 + len(a) > p2 + len(b):
            print('>')
        elif p1 + len(a) > p2 + len(b):
            print('<')
        else:
            sa, sb = a + '0' * p1, b + '0' * p2
            if sa > sb:
                print('>')
            elif sa < sb:
                print('<')
            else:
                print('=')


main()
