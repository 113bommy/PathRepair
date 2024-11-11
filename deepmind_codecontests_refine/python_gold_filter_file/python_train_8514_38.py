from bisect import bisect_left

s = input()
t = input()

oa = ord('a')

l = [[] for _ in range(26)]
for i,c in enumerate(s):
    l[ord(c) - oa].append(i)

x = -1
p = 0
for c in t:
    ll = l[ord(c)-oa]
    if len(ll)==0:
        print(-1)
        exit()

    y = bisect_left(ll, x)
    if y==len(ll):
        p += 1
        x = ll[0]+1
    else:
        x = ll[y]+1

print(p*len(s)+x)