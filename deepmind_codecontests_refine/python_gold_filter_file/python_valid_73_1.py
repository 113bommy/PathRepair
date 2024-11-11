import sys

input = sys.stdin.readline


def ri(): return [int(i) for i in input().split()]


def main():
    j = ri()[0]

    for _ in range(j):
        n = ri()[0]
        a = ri()
        b = sorted(a)
        if a == b:
            print(0)
            continue
        for i in range(1, 10000):
            odd = (i % 2)
            _from = 0 if odd == 1 else 1
            _to = n - 2 if odd == 1 else n - 1
            for j in range(_from, _to, 2):
                if a[j + 1] < a[j]:
                    a[j], a[j + 1] = a[j + 1], a[j]
            # print(f'i={i} a={a}')
            if a == b:
                print(i)
                break


main()
