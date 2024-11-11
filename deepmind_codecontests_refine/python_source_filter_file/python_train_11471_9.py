#!/usr/bin/env python3


def soln() -> None:
    def logic() -> None:
        n = int(input())
        arr = sorted([int(x) for x in input().split()])

        for i in range(0, n, 2):
            if arr[i] != arr[i + 1]:
                print('NO')
                return

        prod = []
        for _ in range(n):
            curr = arr.pop() * arr.pop(0)
            prod.append(curr)
            arr.pop()
            arr.pop(0)

        for i in prod:
            if i != prod[0]:
                print('NO')
                return
        else:
            print('YES')

        # print(prod)

    for _ in range(int(input())):
        logic()


if __name__ == '__main__':
    soln()
