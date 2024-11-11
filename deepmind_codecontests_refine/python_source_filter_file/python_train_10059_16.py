import sys, threading

sys.setrecursionlimit(10 ** 6)

scan = lambda: map(int, input().split())

string = input()
a, ab, aba = 0, 0, 0
size = 0
for i in string:
    size +=1
    if i == 'a':
        a += 1
        aba = max(aba+1, a, ab+1)
    else:
        ab = max(ab+1, aba, a+1)

print(max(a, ab, aba))