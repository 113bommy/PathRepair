from sys import stdin
from collections import defaultdict
import bisect
n = int(stdin.readline())
# n, m = map(int, stdin.readline().strip().split())
alist = list(map(int, stdin.readline().strip().split()))
blist = list(map(int, stdin.readline().strip().split()))

d = defaultdict(int)
dposkeys = set()
dnegkeys = set()

poscount = 0
for i in range(n):
    t = alist[i] - blist[i]
    d[t] += 1
    if t>0:
        poscount += 1
        dposkeys.add(t)
    else:
        dnegkeys.add(t)

if len(d.keys()) == len(dposkeys):
    # all positive
    print((n*(n-1))//2)
    exit()


del alist, blist

visited = set()
# dposkeys = sorted(list(dposkeys), reverse = True)
dposkeys = sorted(list(dposkeys))


# prefix sum
pref = [0]
t = 0
for k in dposkeys:
    t += d[k]
    pref.append(t)

pref[0] = t
for i in range(1, len(pref)):
    pref[i] = t - pref[i]

# print(d)
# print(pref)

nmpairs = 0
for k1 in dnegkeys:

    ind = bisect.bisect_left(dposkeys, -k1 + 1)
    nmpairs += pref[ind]

    # print(dposkeys, ind, k1, pref[ind])

    # Instead of linear search over here... do binary search. 
    # for k2 in dposkeys:
    #     if (k1 + k2)>0 and ((k1, k2) not in visited) and ((k2, k1) not in visited) and k1!=k2:
    #         # i < j
    #         visited.add((k1, k2))
    #         # ai - bi + aj - bj > 0
    #         # print(k1, k2, d[k1], d[k2])
    #         nmpairs += (d[k1]*d[k2])

    #     elif (k1+k2)<=0:
    #         break

        # elif k1 == k2 and d[k1]>1 and k1 > 0 :
        #     nmpairs += ((d[k1]*(d[k1]- 1))//2)

print(nmpairs + ((poscount)*(poscount-1))//2)


