class RollingHash():
    def __init__(self, s):
        self.length = len(s)
        self.base1 = 1009
        self.base2 = 1000
        self.mod1 = 10**9 + 7
        self.mod1 = 10**9 + 9
        self.hash1 = [0] * (self.length + 1)
        self.hash2 = [0] * (self.length + 1)
        self.pow1 = [1] * (self.length + 1)
        self.pow2 = [1] * (self.length + 1)

        for i in range(self.length):
            self.hash1[i+1] = (self.hash1[i] + ord(s[i])) * self.base1 % self.mod1
            self.hash2[i+1] = (self.hash2[i] + ord(s[i])) * self.base2 % self.mod2
            self.pow1[i+1] = self.pow1[i] * self.base1 % self.mod1
            self.pow2[i+1] = self.pow2[i] * self.base2 % self.mod2
        
    def get(self, l, r):
        t1 = ((self.hash1[r] - self.hash1[l] * self.pow1[r-l]) % self.mod1 + self.mod1) % self.mod1
        t2 = ((self.hash2[r] - self.hash2[l] * self.pow2[r-l]) % self.mod2 + self.mod2) % self.mod2
        return (t1, t2)

t_tmp = input().rstrip()
s = input().rstrip()

# Same character goes to infinity
if t_tmp.count(t_tmp[0]) == len(t_tmp) and s.count(s[0]) == len(s) and s[0] == t_tmp[0]:
    print(-1)
    exit()

t = ""
while len(t) < len(s):
    t += t_tmp
max_ans = (len(t) * 2) // len(s)
t = t * 3
lent = len(t)
lens = len(s)

RHt = RollingHash(t)
RHs = RollingHash(s)
s_hash = RHs.get(0, lens)

match = [0] * (lent - lens + 1)
for i in range(lent - lens + 1):
    if RHt.get(i, i+lens) == s_hash:
        match[i] = 1
ans = max(match[:lens])
for i in range(len(match) - lens):
    if match[i+lens] != 0:
        match[i+lens] += match[i]
        ans = max(ans, match[i+lens])

if ans > max_ans:
    print(-1)
else:
    print(ans)