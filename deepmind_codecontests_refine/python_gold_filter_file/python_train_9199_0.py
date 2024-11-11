p = 31
q = 1000000007
p0 = 27
q0 = 2147483647

class hstr:
    def __init__(self, s):
        self.h = [0]
        self.pq = [1]
        self.h0 = [0]
        self.pq0 = [1]
        n = len(s)
        for i in range(n):
            self.h += [(self.h[i] * p + ord(s[i])) % q]
            self.pq += [(self.pq[i] * p) % q]
            self.h0 += [(self.h0[i] * p0 + ord(s[i])) % q0]
            self.pq0 += [(self.pq0[i] * p0) % q0]
    def get(self, l, r):
        return ((self.h[r] - self.h[l] * self.pq[r - l]) % q + q) % q
    def get0(self, l, r):
        return ((self.h0[r] - self.h0[l] * self.pq0[r - l]) % q0 + q0) % q0


from sys import stdout
from sys import stdin
def get():
    return stdin.readline().strip()
def getf():
    return [int(i) for i in get().split()]
def put(a, end = "\n"):
    stdout.write(str(a) + end)
def putf(a, sep = " ", end = "\n"):
    stdout.write(sep.join([str(i) for i in a]) + end)

def main():
    s = get()
    a = get()
    h = hstr(s)
    k = int(get())
    r = []
    for i in a:
        if(i == "1"):
            r += [0]
        else:
            r += [1]
    ns = [0]
    for i in s:
        ns += [r[ord(i) - 97] + ns[-1]]
    st = set()
    ans = 0
    n = len(s)
    for i in range(n):
        for j in range(i + 1, n + 1):
            res = h.get(i, j) * h.get0(i, j)
            if(res not in st):
                st.add(res)
                if(ns[j] - ns[i] <= k):
                    ans += 1
    put(ans)
main()