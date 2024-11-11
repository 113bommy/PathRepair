from itertools import chain
import math


def _is_sorted(seq):
    return all(seq[i-1] <= seq[i] for i in range(1, len(seq)))


def _iter_states(p_seq, swap_halfs_first):
    p_seq = tuple(p_seq)
    n = len(p_seq) // 2
    assert len(p_seq) == 2*n
    yield p_seq
    
    if swap_halfs_first:
        p_seq = p_seq[n:] + p_seq[:n]
        yield p_seq
    del swap_halfs_first
    
    for i in range(1024):
        p_seq = chain.from_iterable(zip(p_seq[1::2], p_seq[0::2]))
        p_seq = tuple(p_seq)
        yield p_seq
        p_seq = p_seq[n:] + p_seq[:n]
        yield p_seq


def _check_min_cost(p_seq, swap_halfs_first):
    cost = 0
    for state in _iter_states(p_seq, swap_halfs_first):
        if _is_sorted(state):
            return cost
        cost += 1
    return math.inf


def f(p_seq):
    p_seq = tuple(p_seq)
    return min(
        _check_min_cost(p_seq, swap_halfs_first=False),
        _check_min_cost(p_seq, swap_halfs_first=True),
    )


def read_ints():
    return map(int, input().split())


n, = read_ints()
p_seq = tuple(read_ints())
assert len(p_seq) == 2*n
del n

result = f(p_seq)
if math.isinf(result):
    result = -1

print(result)
