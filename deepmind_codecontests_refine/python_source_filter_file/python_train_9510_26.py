#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

n, = readln()
d = readln()
i = d.index(min(d))
print(i + 1 if len([_ for _ in d if _ == d[i]]) == 1 else 'Still Rozlil')
