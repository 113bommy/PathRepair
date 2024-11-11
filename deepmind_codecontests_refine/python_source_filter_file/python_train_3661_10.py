from collections import deque


def main():
    n, q = map(int, input().split())
    x = deque(map(int, input().split()))
    max_x = max(x)

    ress_first = list()
    for _ in range(n):
        if x[0] == max_x:
            break
        ress_first.append(f'{x[0]} {x[1]}')
        a = x.popleft()
        b = x.popleft()
        x.appendleft(max(a, b))
        x.append(min(a, b))
    len_first = len(ress_first)

    for _ in range(q):
        m = int(input())
        if m - 1 < len_first:
            print(ress_first[m - 1])
        else:
            print(f'{x[0]} {x[(m - len_first) % (n - 1)]}')


if __name__ == '__main__':
    main()
