from collections import defaultdict
class RollingHash():
    def __init__(self, s, base, mod):
        self.mod = mod
        self.pw = pw = [1]*(len(s)+1)

        l = len(s)
        self.h = h = [0]*(l+1)

        v = 0
        for i in range(l):
            h[i+1] = v = (v * base + ord(s[i])) % mod
        v = 1
        for i in range(l):
            pw[i+1] = v = v * base % mod
    def get(self, l, r):
        return (self.h[r] - self.h[l] * self.pw[r-l]) % self.mod

N = int(input())
Slist = []
for i in range(N):
    S = input()
    Slist.append(S)
Slist.sort(key=len)
dic = defaultdict(lambda:defaultdict(int))
ans = 0
for S in Slist:
    alp = set()
    l = len(S)
    RH = RollingHash(S,37,10**9+7)
    for i in range(len(S)):
        alp.add(S[i])
        alpdic = dic[RH.get(i+1,l)]
        for X in alpdic.keys():
            if X in alp:
                ans += alpdic[X]
    dic[RH.get(1,l)][S[0]] += 1
print(ans)
