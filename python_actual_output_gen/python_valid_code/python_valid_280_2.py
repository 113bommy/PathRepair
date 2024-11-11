from sys import stdin

def subseq(xs, n, m):
    if n > 1:
        sl = subseq(xs[:n//2], n//2, m-1)
        sr = subseq(xs[n//2:], n - n//2, m-1)
        return combine(sl, sr, m)
    return xs

def combine(sl, sr, m):
    seq = {s1+s2 for s1 in sl for s2 in sr}.union(sl, sr)
    seql = sorted(seq, key=len, reverse=True) [:m]
    return seql

n,k = map(int, input().split())
s = input()

seqs = subseq(s, n, k-1)
if len(seqs) < k-1:
    print (-1)
else:
    slengths = map((lambda x: n - len(x)), seqs)
    result = sum(slengths)
    if len(seqs) == k-1:
        result += n
    print(result)