from collections import deque
import sys


def input():
    return sys.stdin.readline().rstrip()


def find_minimum_divisors(M):
    res = set([])
    for i in range(1, M + 1):
        if i * i > M:
            break
        if M % i == 0:
            res.add(i)
            res.add(M//i)
    res.remove(1)
    return list(res)


def slv():
    n = int(input())
    a = list(map(int, input().split()))
    b = deque()
    for i in range(n):
        if a[i] == 1:
            b.append(i)
    if len(b) == 1:
        print(-1)
        return
    final_ans = 1 << 128
    for div in find_minimum_divisors(len(b)):
        B = b.copy()
        ans = 0
        for _ in range(len(b)//div):
            array = []
            for _ in range(div):
                array.append(B.popleft())

            cost = sum(array) - array[0] * div

            tmpmincost = cost

            for i in range(div - 1):
                d = array[i + 1] - array[i]
                cost += (2 * (i + 1) - div) * d
                tmpmincost = min(tmpmincost, cost)
                assert tmpmincost >= 0
            ans += cost
        final_ans = min(final_ans, ans)
    print(final_ans)
    return


def main():
    t = 1
    for i in range(t):
        slv()
    return


if __name__ == "__main__":
    main()
