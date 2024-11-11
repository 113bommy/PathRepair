from math import log2, ceil


class SegmentTree:
    def __init__(self, n):
        self.n = n
        tn = 2 ** ceil(log2(n))
        self.a = [2 ** 31 - 1] * (tn * 2)
        self.tn = tn

    def find(self, s, t):
        return self.__find(1, 0, st.n - 1, s, t)

    def __find(self, c, l, r, s, t):
        if self.a[c] == -1:
            return self.a[c // 2]
        if s <= l and r <= t:
            return self.a[c]
        mid = (l + r) // 2
        if t <= mid:
            return self.__find(c * 2, l, mid, s, t)
        elif s > mid:
            return self.__find(c * 2 + 1, mid + 1, r, s, t)
        else:
            return min(
                self.__find(c * 2, l, mid, s, mid),
                self.__find(c * 2 + 1, mid + 1, r, mid + 1, t))

    def update(self, s, t, x):
        self.__update(1, 0, self.n - 1, s, t, x)

    def __update(self, c, l, r, s, t, x, f=None):

        if f is None and self.a[c] == -1:
            f = self.a[c // 2]

        if l == s and r == t:
            return self.__set(c, x)

        mid = (l + r) // 2
        if t <= mid:
            rv, f = self.__get_child(c, c * 2 + 1, f)
            u = min(self.__update(c * 2, l, mid, s, t, x, f), rv)
        elif s > mid:
            lv, f = self.__get_child(c, c * 2, f)
            u = min(lv, self.__update(c * 2 + 1, mid + 1, r, s, t, x, f))
        else:
            u = min(
                self.__update(c * 2, l, mid, s, mid, x, f),
                self.__update(c * 2 + 1, mid + 1, r, mid + 1, t, x, f))
            if f is not None:
                u = min(f, u)
        self.a[c] = u

        return u

    def __set(self, c, x):
        self.a[c] = x
        if c < self.tn:
            self.a[c * 2] = self.a[c * 2 + 1] = -1
        return x

    def __get_child(self, c, child, f):
        if f is not None:
            return self.__set(child, f), f
        v = self.a[child]
        if v == -1:
            f = self.a[c]
            v = self.__set(child, f)
        return v, f


n, q = map(int, input().split())
st = SegmentTree(n)
buf = []
for _ in range(q):
    q_type, *query = map(int, input().split())
    if q_type == 0:
        st.update(*query)
    else:
        buf.append(st.find(*query))
        # print(_, query, st.a)
print('\n'.join(map(str, buf)))