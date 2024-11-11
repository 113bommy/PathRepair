#!/usr/bin/env python


def do(n, m, ss, tt):
    max_hit_num = -1
    hit_indices = [True] * n
    for i in range(m - n + 1):
        matched = tt[i:i + n]
        hit = [sc == mc for sc, mc in zip(ss, matched)]
        hit_num = len([f for f in hit if f])

        if hit_num > max_hit_num:
            max_hit_num = hit_num
            hit_indices = [True] * n
            for hi in range(n):
                hit_indices[hi] = hit_indices[hi] & hit[hi]

    return n - max_hit_num, ' '.join(str(e) for e, x in enumerate(hit_indices, start=1) if not x)


def test():
    a, b = do(3, 5, 'abc', 'xaybz')
    assert a == 2
    assert b == '2 3'

    a, b= do(4, 10,'abcd','ebceabazcd')
    assert a == 1
    assert b == '2'

    a, b= do(1, 1,'a','a')
    assert a == 0
    assert b == ''

    a, b= do(1, 1,'a','z')
    assert a == 1
    assert b == '1'


def main():
    n, m = list(map(int, input().split()))
    s = input().rstrip()
    t = input().rstrip()
    a, b = do(n, m, s, t)
    print(a)
    print(b)


if __name__ == '__main__':
    test()
