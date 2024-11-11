# 入力チェックオフ

class LazySegmentTree:


    __slots__ = ["n", "original_size", "log", "data", "lazy", "me", "oe", "fmm", "fmo", "foo"]


    def __init__(self, length_or_list, monoid_identity, operator_identity, func_monoid_monoid, func_monoid_operator, func_operator_operator):
        self.me = monoid_identity
        self.oe = operator_identity
        self.fmm = func_monoid_monoid
        self.fmo = func_monoid_operator
        self.foo = func_operator_operator

        if isinstance(length_or_list, int):
            self.original_size = length_or_list
            self.log = (self.original_size - 1).bit_length()
            self.n = 1 << self.log
            self.data = [self.me] * (self.n * 2)
            self.lazy = [self.oe] * (self.n * 2)
        elif isinstance(length_or_list, list):
            self.original_size = len(length_or_list)
            self.log = (self.original_size - 1).bit_length()
            self.n = 1 << self.log
            self.data = [self.me] * self.n + length_or_list + [self.me] * (self.n - self.original_size)
            for i in range(self.n-1, 0, -1):
                self.data[i] = self.fmm(self.data[2*i], self.data[2*i+1])
            self.lazy = [self.oe] * (self.n * 2)
        else:
            raise TypeError(f"The argument 'length_or_list' must be an integer or a list, not {type(length_or_list).__name__}")
            

    def replace(self, index, value):
        # if index < -self.original_size or self.original_size <= index:
        #     raise IndexError("LazySegmentTree index out of range")
        # if index < 0:
        #     index += self.original_size

        index += self.n

        # propagation
        for shift in range(self.log, 0, -1):
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


    def __getitem__(self, index):
        # if index < -self.original_size or self.original_size <= index:
        #     raise IndexError("LazySegmentTree index out of range")
        # if index < 0:
        #     index += self.original_size

        index += self.n

        # propagation
        for shift in range(self.log, 0, -1):
            i = index >> shift
            self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
            self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
            self.data[i] = self.fmo(self.data[i], self.lazy[i])
            self.lazy[i] = self.oe

        # self.data[index] = self.fmo(self.data[index], self.lazy[index])
        # self.lazy[index] = self.oe

        return self.data[index]


    def effect(self, l, r, operator):
        # if l < 0:
        #     l += self.original_size
        # if r < 0:
        #     r += self.original_size
        # if not 0 <= l <= r <= self.original_size:
        #     raise IndexError("LazySegmentTree index out of range")

        if l == r:
            return

        l += self.n
        r += self.n

        l0 = l
        r0 = r - 1
        while l0 % 2 == 0:
            l0 //= 2
        while r0 % 2 == 1:
            r0 //= 2
        
        # propagation
        for shift in range(self.log, 0, -1):
            i = l >> shift
            if i << shift != l:
                self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
                self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
                self.data[i] = self.fmo(self.data[i], self.lazy[i])
                self.lazy[i] = self.oe
            if i == r >> shift:
                continue
            i = r >> shift
            if i << shift != r:
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
        # if l < 0:
        #     l += self.original_size
        # if r < 0:
        #     r += self.original_size
        # if not 0 <= l <= r <= self.original_size:
        #     raise IndexError("LazySegmentTree index out of range")

        l += self.n
        r += self.n

        # propagation
        for shift in range(self.log, 0, -1):
            i = l >> shift
            if i << shift != l:
                self.lazy[2*i]   = self.foo(self.lazy[2*i],   self.lazy[i])
                self.lazy[2*i+1] = self.foo(self.lazy[2*i+1], self.lazy[i])
                self.data[i] = self.fmo(self.data[i], self.lazy[i])
                self.lazy[i] = self.oe
            if i == r >> shift:
                continue            
            i = r >> shift
            if i << shift != r:
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


def atc2():
    # Monoid:   ((0の数), (1の数), (転倒数))
    # Operator: 反転するか? (1 or 0) 

    import sys
    input = sys.stdin.buffer.readline

    N, Q = map(int, input().split())
    monoid_data = [(0, 1, 0) if A == b'1' else (1, 0, 0) for A in input().split()]

    def fmm(m1, m2):
        return (m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2] + m1[1] * m2[0])

    def fmo(m1, o1):
        if o1:
            return (m1[1], m1[0], m1[0] * m1[1] - m1[2])
        else:
            return m1 

    def foo(o1, o2):
        return o1 ^ o2

    lst = LazySegmentTree(monoid_data, (0, 0, 0), 0, fmm, fmo, foo)
    ans = []
    for _ in range(Q):
        T, L, R = map(int, input().split())
        if T == 1:
            lst.effect(L-1, R, 1)
        else:
            ans.append(lst.folded(L-1, R)[2])
    print('\n'.join(map(str, ans)))

if __name__ == "__main__":
    atc2()