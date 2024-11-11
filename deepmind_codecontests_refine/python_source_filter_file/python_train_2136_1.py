from time import time


opposite = {
    'N': 'S',
    'S': 'N',
    'E': 'W',
    'W': 'E'
}
otr = str.maketrans(opposite)

bits = {
    'N': 0,
    'S': 1,
    'E': 2,
    'W': 3,
}

Q = 4294967291


def combine(h, v, q):
    return (h<<2 | v) % q


def combinel(h, v, q, s):
    return (v*s + h) % q


def flip(s):
    return ''.join(reversed(s.translate(otr)))


def solvable(p1, p2):
    h1 = 0
    h2 = 0
    s = 0
    for i in reversed(range(len(p1))):
        n1 = bits[p1[i]]
        n2 = bits[opposite[p2[i]]]
        h1 = combine(h1, n1, Q)
        h2 = combinel(h2, n2, Q, s)
        if h1 == h2 and  p1[i:] == flip(p2[i:]):
            return False
        s = (s<<2) % Q
    return True


if __name__ == '__main__':
    n = int(input())
    p1 = input()
    p2 = input()
    print('YES' if solvable(p1, p2) else 'NO')
