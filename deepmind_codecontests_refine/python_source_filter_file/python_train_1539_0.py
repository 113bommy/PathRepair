class LazySegmentTree:

    __slots__ = ["n", "data", "lazy", "me", "oe", "fmm", "fmo", "foo"]

    def __init__(self, monoid_data, monoid_identity, operator_identity, func_monoid_monoid, func_monoid_operator, func_operator_operator):
        self.me = monoid_identity
        self.oe = operator_identity
        self.fmm = func_monoid_monoid
        self.fmo = func_monoid_operator
        self.foo = func_operator_operator

        self.n = len(monoid_data)
        self.data = monoid_data * 2
        for i in range(self.n-1, 0, -1):
            self.data[i] = self.fmm(self.data[2*i], self.data[2*i+1])
        self.lazy = [self.oe] * (self.n * 2)


    def replace(self, index, value):
        index += self.n

        # propagation
        for shift in range(index.bit_length()-1, 0, -1):
            i = index >> shift
            self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
            self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
            self.data[i] = self.fmo(self.data[i], self.lazy[i])
            self.lazy[i] = self.oe

        # update
        self.data[index] = value
        self.lazy[index] = self.oe

        # recalculation
        i = index
        while i > 1:
            i //= 2
            self.data[i] = self.fmm( self.fmo(self.data[2*i], self.lazy[2*i]), self.fmo(self.data[2*i+1], self.lazy[2*i+1]) )
            self.lazy[i] = self.oe


    def effect(self, l, r, operator):
        l += self.n
        r += self.n
        l0 = l
        r0 = r - 1
        while l0 % 2 == 0:
            l0 //= 2
        while r0 % 2 == 1:
            r0 //= 2

        # propagation
        for shift in range(l0.bit_length()-1, 0, -1):
            i = l0 >> shift
            self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
            self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
            self.data[i] = self.fmo(self.data[i], self.lazy[i])
            self.lazy[i] = self.oe
        for shift in range(r0.bit_length()-1, 0, -1):
            i = r0 >> shift
            self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
            self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
            self.data[i] = self.fmo(self.data[i], self.lazy[i])
            self.lazy[i] = self.oe

        # effect
        while l < r:
            if l % 2:
                self.lazy[l] = self.foo(self.lazy[l], operator)
                l += 1
            if r % 2:
                r -= 1
                self.lazy[r] = self.foo(self.lazy[r], operator)
            l //= 2
            r //= 2

        # recalculation
        i = l0
        while i > 1:
            i //= 2
            self.data[i] = self.fmm( self.fmo(self.data[2*i], self.lazy[2*i]), self.fmo(self.data[2*i+1], self.lazy[2*i+1]) )
            self.lazy[i] = self.oe
        i = r0
        while i > 1:
            i //= 2
            self.data[i] = self.fmm( self.fmo(self.data[2*i], self.lazy[2*i]), self.fmo(self.data[2*i+1], self.lazy[2*i+1]) )
            self.lazy[i] = self.oe
            
        
    def folded(self, l, r):
        l += self.n
        r += self.n
        l0 = l
        r0 = r - 1
        while l0 % 2 == 0:
            l0 //= 2
        while r0 % 2 == 1:
            r0 //= 2

        # propagation
        for shift in range(l0.bit_length()-1, 0, -1):
            i = l0 >> shift
            self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
            self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
            self.data[i] = self.fmo(self.data[i], self.lazy[i])
            self.lazy[i] = self.oe
        for shift in range(r0.bit_length()-1, 0, -1):
            i = r0 >> shift
            self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
            self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
            self.data[i] = self.fmo(self.data[i], self.lazy[i])
            self.lazy[i] = self.oe

        # fold
        left_folded = self.me
        right_folded = self.me
        while l < r:
            if l % 2:
                left_folded = self.fmm(left_folded, self.fmo(self.data[l], self.lazy[l]))
                l += 1
            if r % 2:
                r -= 1
                right_folded = self.fmm(self.fmo(self.data[r], self.lazy[r]), right_folded)
            l //= 2
            r //= 2
        return self.fmm(left_folded, right_folded)

import sys
input = sys.stdin.readline
h, w = map(int, input().split())
def fmo(m1, o1):
    if o1 == -1:
        return m1
    return o1
def foo(o1, o2):
    if o2 == -1:
        return o1
    return o2
INF = 10**6
lst_max = LazySegmentTree(list(range(w)), -INF, -1, max, fmo, foo)
lst_min = LazySegmentTree([0]*w, INF, -1, min, fmo, foo)
for i in range(h):
    a, b = map(int, input().split())
    a -= 1
    l_max = lst_max.folded(a, b)
    lst_max.effect(a, b, -INF)
    lst_min.effect(a, b, INF)
    if b < w:
        x = lst_max.folded(b, b+1)
        lst_max.replace(b, max(l_max, x))
        y = lst_min.folded(b, b+1)
        lst_min.replace(b, min(b, y))
    ans = lst_min.folded(0, w)
    if ans == INF:
        print(-1)
    else:
        ans += i+1
        print(ans)