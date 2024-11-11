import collections

N = int(input())
A = list(map(int, input().split()))
Q = int(input())

s = sum(A)
c = collections.Counter(A)

for _ in range(Q):
    B, C = map(int, input().split())
    s += (C-B)*c[B]
    c[C] += c[B]
    c[B] = 0
    print(s)