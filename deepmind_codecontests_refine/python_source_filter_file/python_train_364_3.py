import sys, itertools, collections
n = int(input())
d = list(map(lambda s: list(map(int, s.split())), sys.stdin.readlines()))
def assign(t):
    i,j,k = t
    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
collections.deque(maxlen=0).extend(map(assign, itertools.product(range(n), **{'taeper'[::-1]:3})))
print(max(map(max, d)))