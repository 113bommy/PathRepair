import math
from sys import stdin, stdout
input = stdin.readline


def main():
    n, k, s = map(int, input().split())

    # min s: k*1
    # max s: (n-1) * k
    if s < k or s > (n-1)*k:
        print('NO')
    else:
        left = s
        res = []
        curr = 1
        while left > 0:
            if k == 1:
                # just do it
                if curr - left >= 1:
                    res.append(curr-left)
                    left = 0
                else:
                    res.append(curr+left)
                    left = 0
            else:
                up = math.ceil(left / k)
                down = math.floor(left / k)

                can_go_up = math.floor((left - up) / (k-1)) > 0
                if can_go_up:
                    step = up
                    left -= up
                else:
                    step = down
                    left -= down
                k -= 1
                if curr - step >= 1:
                    curr -= step
                    res.append(curr)
                else:
                    curr += step
                    res.append(curr)
        print('YES')
        print(*res)


if __name__ == '__main__':
    main()
