#! /usr/bin/python3
from collections import defaultdict
for _ in range(int(input())):
    n = int(input())
    a = list(map(int , input().split()))
    a.sort()
    grp_size = a[0]
    c = 0
    for i in a:
        if i<=grp_size+1:
            c+=1
            grp_size=0
        else:
            grp_size+=1
    print(c)

    