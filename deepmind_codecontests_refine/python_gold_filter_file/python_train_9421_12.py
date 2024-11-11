from math import sqrt, pow, log, log2, log10, exp
from copy import deepcopy


def read_ints():
    return list(map(int, input().split()))


def read_int():
    return read_ints()[0]


def read_floats():
    return list(map(float, input().split()))


def read_float():
    return read_floats()[0]


def one_dim_array(value, n):
    return [deepcopy(value) for x in range(n)]


def two_dim_array(value, n, m):
    return [[deepcopy(value) for x in range(m)] for x in range(n)]


def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, sqrt(n) + 1):
        if n % i == 0:
            return False
    return True


def max_len_sublist(l, f):
    start, max_length, length = 0, 0, 0
    for i in range(1, len(l)):
        if f(l[i], l[i - 1]):
            length += 1
        else:
            if max_length < length:
                start = i - length
                max_length = length
            length = 0
    return start, max_length


def tf_to_yn(b):
    return 'YES' if b else 'NO'


n = read_int()
d = set()
r = []
for i in range(1, n * n + 1):
    a, b = read_ints()
    if (a not in d) and (b+n not in d):
        d.add(a)
        d.add(b+n)
        r.append(str(i))
print(' '.join(r))
