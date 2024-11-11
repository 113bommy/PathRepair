from collections import defaultdict, Counter
from bisect import bisect, bisect_left
from math import sqrt, gcd, ceil, factorial


# file = open("input.txt", "r")

MOD = 10**9 + 7
inf = float("inf")
ans_ = []
def read(): return list(map(int, input().strip().split()))
# def read(f):return list(map(int, f.readline().strip().split()))

# for _ in range(int(input())):
n = int(input()); x = input().strip()
d  = defaultdict(int)
a = []
dic = {4:[3,2,2], 6:[5,3], 8:[7,2,2,2], 9:[7,3,3,2]}
for i in x:
    i = int(i)
    if i == 1:continue
    elif i in dic:a.extend(dic[i])
    else:a.append(i)
a.sort(reverse=True)
ans_.append(("").join(map(str,a)))
    

for i in ans_:
    print(i)