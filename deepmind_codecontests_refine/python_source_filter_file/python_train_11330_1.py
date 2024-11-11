class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0]*(n+1)

    def __iter__(self):
        psum = 0
        for i in range(self.size):
            csum = self.sum(i+1)
            yield csum - psum
            psum = csum
        raise StopIteration()

    def __str__(self):  # O(nlogn)
        return str(list(self))

    def sum(self, i):
        # [0, i) の要素の総和を返す
        if not (0 <= i <= self.size): raise ValueError("error!")
        s = 0
        while i>0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        if not (0 <= i < self.size): raise ValueError("error!")
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def __getitem__(self, key):
        if not (0 <= key < self.size): raise IndexError("error!")
        return self.sum(key+1) - self.sum(key)

    def __setitem__(self, key, value):
        # 足し算と引き算にはaddを使うべき
        if not (0 <= key < self.size): raise IndexError("error!")
        self.add(key, value - self[key])



S = input()
N = len(S)
cnt = [0]*26
for c in S:
    cnt[ord(c)-97] += 1
odd = -1
for i, cn in enumerate(cnt):
    if cn%2 != 0:
        if odd == -1:
            odd = i
        else:
            print(-1)
            exit()
    cnt[i] //= 2
#cnt2 = [0]*26
L = [[] for _ in range(26)]
n = N//2 + 1
B = []
for c in S:
    c_int = ord(c)-97
    if cnt[c_int] == 0:
        if c_int == odd:
            B.append(1)
            odd = -1
        else:
            p = L[c_int].pop()
            B.append(p)
    else:
        L[c_int].append(n)
        B.append(0)
        n-=1
        cnt[c_int] -= 1
print(B)

bit = Bit(N//2+2)
ans = 0
for i, b in enumerate(B):
    ans += i - bit.sum(b+1)
    bit.add(b, 1)
print(ans)
