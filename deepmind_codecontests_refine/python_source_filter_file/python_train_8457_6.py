from collections import *
for t in range(int(input())):
    n = int(input())
    l = [*map(int,input().split(" "))]
    l_sorted = sorted(l)
    t = [*map(int,input().split(" "))]
    i = 0
    flag = True
    c = Counter(t)
    if l_sorted == l:
        print("Yes")
    elif n == c[0] or n == c[1]:
        print("No")
    else:
        if c[0] > 0 and c[1] > 1:
            print("Yes")
        else:
            print("No")
        