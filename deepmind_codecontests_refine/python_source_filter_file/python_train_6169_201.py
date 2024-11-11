def func():
    n = int(input())
    if n % 2 == 0:
        print('YES')
    else:
        print('NO')


def main():
    for _ in range(int(input())):
        func()


main()