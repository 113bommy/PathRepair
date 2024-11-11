#!/usr/bin/python3

def atoi(c):
    return ord(c) - ord('0')

table = [(), #dummy
        ('.',',','!','?'),\
        ('a','b','c'),
        ('d','e','f'),
        ('g','h','i'),
        ('j','k','l'),
        ('m','n','o'),
        ('p','q','r','s'),
        ('t','u','v'),
        ('w','x','y','z')]

n = int(input())
for i in range(n):
    digits = list(input())
    s = ""
    c = ''
    m = 0
    for d in digits:
        if d == '0':
            s += c
            c = ''
            m = 0
        else:
            c = table[atoi(d)][m]
            m = (m + 1) % len(table[atoi(d)])
    print(s)