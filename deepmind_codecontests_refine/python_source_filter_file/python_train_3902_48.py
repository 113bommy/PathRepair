__author__ = 'denis'


n, m = map(int, input().split())
s, t, s2, t2= '#' * m, '.' * (m-1), '#' * m, '.' * (m-1)
for i in range(n):
    print([s, t + '#', s2, t2 + '#'][i % 4])