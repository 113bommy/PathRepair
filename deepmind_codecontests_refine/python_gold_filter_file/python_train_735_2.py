from sys import stdin
from math import gcd


def main():
    input()
    l = stdin.read().splitlines()
    d = [3., 1., 2., 2., 2., 1.] * 16667
    for i in range(4, 100001):
        for j in range(i, 100001, i):
            d[j] += 1.
    for i, s in enumerate(l):
        a, b, c = map(int, s.split())
        k = gcd(b, c)
        ab = d[gcd(a, b)]
        ac = d[gcd(a, c)]
        bc = d[k]
        abc = d[gcd(a, k)]
        asz = d[a] - ab - ac + abc
        bsz = d[b] - bc - ab + abc
        csz = d[c] - ac - bc + abc
        absz = ab - abc
        bcsz = bc - abc
        acsz = ac - abc
        l[i] = '%d' % (asz * bsz * csz +
                       (absz * (asz + bsz) * csz) +
                       (bcsz * (bsz + csz) * asz) +
                       (acsz * (asz + csz) * bsz) +
                       (abc * (asz * bsz + asz * csz + bsz * csz)) +
                       (abc * (absz + bcsz + acsz) * (asz + bsz + csz)) +
                       ((asz + bsz + csz + absz + bcsz + acsz) * (abc * (abc + 1) * .5)) +
                       (absz * bcsz * acsz) +
                       ((absz * (absz + 1.) * d[c]) +
                        (bcsz * (bcsz + 1.) * d[a]) +
                        (acsz * (acsz + 1.) * d[b])) * .5 +
                       ((asz + bsz + csz + abc) * (absz * acsz + absz * bcsz + bcsz * acsz)) +
                       (abc + (abc * (abc - 1.)) + (abc * (abc - 1.) * (abc - 2.) / 6.)))
    print('\n'.join(map(str, l)))


if __name__ == '__main__':
    main()
