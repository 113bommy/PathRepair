
from math import ceil,sqrt
from collections import defaultdict




def solve():


    n = int(input())
    l = list(map(int,input().split()))
    hash = defaultdict(list)
    for i in range(n):
        hash[l[i]].append(i+1)


    l.sort()
    ans = [0]*(n+1)
    maxi = 0
    for i in range(n):
        if l[i] == l[0]:
           z = hash[l[i]].pop(0)
           maxi = max(z,maxi)
           ans[z] = -1

        else:
            z = hash[l[i]].pop(0)
            maxi = max(z,maxi)
            ans[z] = maxi-z-1

    print(*ans[1:])









solve()