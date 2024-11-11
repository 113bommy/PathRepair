# https://codeforces.com/problemset/problem/1155/B

import math

def find_nth(haystack, needle, n):
    first_idx = haystack.find(needle)
    while first_idx > 0 and n-1 > 0:
        idx = haystack.find(needle, first_idx + 1)
        if idx != -1:
            n -= 1
            first_idx = idx
        else:
            first_idx = -1
            break
    return first_idx

n = int(input())
s = str(input())

v = math.ceil((n-11)/2)
p = math.floor((n-11)/2)

if s.count("8") < p:
    print("NO")
else:
    s = s.replace("8", "", p)
    if s.find("8") > v:
        print("NO")
    else:
        print("YES")




