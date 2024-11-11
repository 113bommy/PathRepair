from collections import Counter

from sys import stdin
input = stdin.readline

for _ in range(int(input())):
    n, c0, c1, h = map(int, input().split())
    s = input().strip()
    c = Counter(s)
    print(c)

    t1 = c0 * c['0'] + c1 * c['1']
    t2 = n * c0 + h * c['1']
    t3 = n * c1 + h * c['0']
    #print(t1,t2,t3)
    print(min(t1,t2,t3))
    #print("==")
