s = list(map(int, input().split()))

k1 = s[0]
k2 = s[1]
k3 = s[2]
will = False

ks = [k1, k2, k3]

if 1 in ks: will = True
if ks.count(2) > 1: will = True
if set(ks) == {3}: will = True
if set(ks) == {2, 4}: will = True

if will: print("YES")
else: print("NO")