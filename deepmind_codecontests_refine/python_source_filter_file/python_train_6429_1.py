from collections import deque
from sys import stdin
lines = deque(line.strip() for line in stdin.readlines())

def nextline():
    return lines.popleft()

def types(cast, sep=None):
    return tuple(cast(x) for x in strs(sep=sep))

def ints(sep=None):
    return types(int, sep=sep)

def strs(sep=None):
    return tuple(nextline()) if sep == '' else tuple(nextline().split(sep=sep))

def main():
    # lines will now contain all of the input's lines in a list
    ints()
    first_pairs = ints()
    first_pairs = tuple(first_pairs[i:i+2] for i in range(0, len(first_pairs), 2))
    second_pairs = ints()
    second_pairs = tuple(second_pairs[i:i+2] for i in range(0, len(second_pairs), 2))
    def compute(p1, p2):
        candidates = []
        for a, b in p1:
            # assume a, b are the real pair
            a_pairs = 0
            b_pairs = 0
            for c, d in p2:
                if len(set([a, b, c, d])) != 3:
                    continue
                if len(set([a, c, d])) == 2:
                    a_pairs += 1
                if len(set([b, c, d])) == 2:
                    b_pairs += 1
            if a_pairs > 0 and b_pairs > 0:
                return -1
            if a_pairs + b_pairs == 1:
                candidates.append((a, b))
        return candidates
    r1 = compute(first_pairs, second_pairs)
    if r1 == -1:
        return -1
    r2 = compute(second_pairs, first_pairs)
    if r2 == -1:
        return -1
    if not r1 or not r2:
        return -1
    shared_number = 0
    for a, b in r1:
        for c, d in r2:
            if a == c and b != d or a == d and b != c:
                if shared_number and a != shared_number:
                    return 0
                shared_number = a
            if b == c and a != d or b == d and a != c:
                if shared_number and b != shared_number:
                    return 0
                shared_number = b
    if shared_number:
        return shared_number
    return -1

if __name__ == '__main__':
    print(main())
