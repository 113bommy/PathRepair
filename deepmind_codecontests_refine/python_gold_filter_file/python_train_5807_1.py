# AC Library Python版
# Author Koki_tkg

'''
internal_type_traits以外は翻訳しました。
practiceは一応全部ACしていますが，
practiceで使っていない関数などの動作は未確認なので保証はしません。
また，C++版をほぼそのまま書き換えているので速度は出ません。　(2020/09/13 by Koki_tkg)
'''
# --------------------<< Library Start >>-------------------- #

# convolution.py
class convolution:
    def __init__(self, a: list, b: list, mod: int):
        self.a, self.b = a, b
        self.n, self.m = len(a), len(b)
        self.MOD = mod
        self.g = primitive_root_constexpr(self.MOD)
    
    def convolution(self) -> list:
        n, m = self.n, self.m
        a, b = self.a, self.b
        if not n or not m: return []
        if min(n, m) <= 60:
            if n < m:
                n, m = m, n
                a, b = b, a
            ans = [0] * (n + m - 1)
            for i in range(n):
                for j in range(m):
                    ans[i + j] += a[i] * b[j] % self.MOD
                    ans[i + j] %= self.MOD
            return ans
        z = 1 << ceil_pow2(n + m - 1)
        a = self.resize(a, z)
        a = self.butterfly(a)
        b = self.resize(b, z)
        b = self.butterfly(b)
        for i in range(z): a[i] = a[i] * b[i] % self.MOD
        a = self.butterfly_inv(a)
        a = a[:n + m - 1]
        iz = self.inv(z)
        a = [x * iz % self.MOD for x in a]
        return a

    def butterfly(self, a: list) -> list:
        n = len(a)
        h = ceil_pow2(n)
        first = True
        sum_e = [0] * 30
        m = self.MOD
        if first:
            first = False
            es, ies = [0] * 30, [0] * 30
            cnt2 = bsf(m - 1)
            e = self.mypow(self.g, (m - 1) >> cnt2); ie = self.inv(e)
            for i in range(cnt2, 1, -1):
                es[i - 2] = e
                ies[i - 2] = ie
                e = e * e % m
                ie = ie * ie % m
            now = 1
            for i in range(cnt2 - 2):
                sum_e[i] = es[i] * now % m
                now = now * ies[i] % m
        for ph in range(1, h + 1):
            w = 1 << (ph - 1); p = 1 << (h - ph)
            now = 1
            for s in range(w):
                offset = s << (h - ph + 1)
                for i in range(p):
                    l = a[i + offset] % m
                    r = a[i + offset + p] * now % m
                    a[i + offset] = (l + r) % m
                    a[i + offset + p] = (l - r) % m
                now = now * sum_e[bsf(~s)] % m
        return a

    def butterfly_inv(self, a: list) -> list:
        n = len(a)
        h = ceil_pow2(n)        
        first = True
        sum_ie = [0] * 30
        m = self.MOD
        if first:
            first = False
            es, ies = [0] * 30, [0] * 30
            cnt2 = bsf(m - 1)
            e = self.mypow(self.g, (m - 1) >> cnt2); ie = self.inv(e)
            for i in range(cnt2, 1, -1):
                es[i - 2] = e
                ies[i - 2] = ie
                e = e * e % m
                ie = ie * ie % m
            now = 1
            for i in range(cnt2 - 2):
                sum_ie[i] = ies[i] * now % m
                now = es[i] * now % m
        for ph in range(h, 0, -1):
            w = 1 << (ph - 1); p = 1 << (h - ph)
            inow = 1
            for s in range(w):
                offset = s << (h - ph + 1)
                for i in range(p):
                    l = a[i + offset] % m
                    r = a[i + offset + p] % m
                    a[i + offset] = (l + r) % m
                    a[i + offset + p] = (m + l - r) * inow % m
                inow = sum_ie[bsf(~s)] * inow % m
        return a

    @staticmethod
    def resize(array: list, sz: int) -> list:
        new_array = array + [0] * (sz - len(array))
        return new_array
    def inv(self, x: int):
        if is_prime_constexpr(self.MOD):
            assert x
            return self.mypow(x, self.MOD - 2)
        else:
            eg = inv_gcd(x)
            assert eg[0] == 1
            return eg[1]
    def mypow(self, x: int, n: int) -> int:
        assert 0 <= n
        r = 1; m = self.MOD
        while n:
            if n & 1: r = r * x % m
            x = x * x % m
            n >>= 1
        return r

# dsu.py
class dsu:
    def __init__(self, n: int):
        self._n = n
        self.parent_or_size = [-1] * self._n
    
    def merge(self, a: int, b: int) -> int:
        assert 0 <= a and a < self._n
        assert 0 <= b and a < self._n
        x = self.leader(a); y = self.leader(b)
        if x == y: return x
        if -self.parent_or_size[x] < -self.parent_or_size[y]: x, y = y, x
        self.parent_or_size[x] += self.parent_or_size[y]
        self.parent_or_size[y] = x
        return x
        
    def same(self, a: int, b: int) -> bool:
        assert 0 <= a and a < self._n
        assert 0 <= b and a < self._n
        return self.leader(a) == self.leader(b)

    def leader(self, a: int) -> int:
        assert 0 <= a and a < self._n
        if self.parent_or_size[a] < 0: return a
        self.parent_or_size[a] = self.leader(self.parent_or_size[a])
        return self.parent_or_size[a]

    def size(self, a: int) -> int: 
        assert 0 <= a and a < self._n
        return -self.parent_or_size[self.leader(a)]

    def groups(self):
        leader_buf = [0] * self._n; group_size = [0] * self._n
        for i in range(self._n):
            leader_buf[i] = self.leader(i)
            group_size[leader_buf[i]] += 1
        result = [[] for _ in range(self._n)]
        for i in range(self._n):
            result[leader_buf[i]].append(i)
        result = [v for v in result if v]
        return result

# fenwicktree.py
class fenwick_tree:
    def __init__(self, n):
        self._n = n
        self.data = [0] * n
    
    def add(self, p: int, x: int):
        assert 0 <= p and p <= self._n
        p += 1
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p
    
    def sum(self, l: int, r: int) -> int:
        assert 0 <= l and l <= r and r <= self._n
        return self.__sum(r) - self.__sum(l)
    
    def __sum(self, r: int) -> int:
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r
        return s

# internal_bit.py
def ceil_pow2(n: int) -> int:
    x = 0
    while (1 << x) < n: x += 1
    return x

def bsf(n: int) -> int:
    return (n & -n).bit_length() - 1

# internal_math.py
def safe_mod(x: int, m: int) -> int:
    x %= m
    if x < 0: x += m
    return x

class barrett:
    def __init__(self, m: int):
        self._m = m
        self.im = -1 // (m + 1)
    def umod(self): return self._m
    def mul(self, a: int, b: int) -> int:
        z = a
        z *= b
        x = (z * im) >> 64
        v = z - x * self._m
        if self._m <= v: v += self._m
        return v        

def pow_mod_constexpr(x: int, n: int, m: int) -> int:
    if m == 1: return 0
    _m = m; r = 1; y = safe_mod(x, m)
    while n:
        if n & 1: r = (r * y) % _m
        y = (y * y) % _m
        n >>= 1
    return r

def is_prime_constexpr(n: int) -> bool:
    if n <= 1: return False
    if n == 2 or n == 7 or n == 61: return True
    if n % 2 == 0: return False
    d = n - 1
    while d % 2 == 0: d //= 2
    for a in [2, 7, 61]:
        t = d
        y = pow_mod_constexpr(a, t, n)
        while t != n - 1 and y != 1 and y != n - 1:
            y = y * y % n
            t <<= 1
        if y != n - 1 and t % 2 == 0: return False
    return True

def inv_gcd(self, a: int, b: int) -> tuple:
    a = safe_mod(a, b)
    if a == 0: return (b, 0)
    s = b; t = a; m0 = 0; m1 = 1
    while t:
        u = s // t
        s -= t * u
        m0 -= m1 * u
        tmp = s; s = t; t = tmp; tmp = m0; m0 = m1; m1 = tmp
    if m0 < 0: m0 += b // s
    return (s, m0)

def primitive_root_constexpr(m: int) -> int:
    if m == 2: return 1
    if m == 167772161: return 3
    if m == 469762049: return 3
    if m == 754974721: return 11
    if m == 998244353: return 3
    divs = [0] * 20
    divs[0] = 2
    cnt = 1
    x = (m - 1) // 2
    while x % 2 == 0: x //= 2
    i = 3
    while i * i <= x:
        if x % i == 0:
            divs[cnt] = i; cnt += 1
            while x % i == 0:
                x //= i
        i += 2
    if x > 1: divs[cnt] = x; cnt += 1
    g = 2
    while True:
        ok = True
        for i in range(cnt):
            if pow_mod_constexpr(g, (m - 1) // div[i], m) == 1:
                ok = False
                break
        if ok: return g
        g += 1

# internal_queue.py
class simple_queue:
    def __init__(self):
        self.payload = []
        self.pos = 0
    def size(self): return len(self.payload) - self.pos
    def empty(self): return self.pos == len(self.payload)
    def push(self, t: int): self.payload.append(t)
    def front(self): return self.payload[self.pos]
    def clear(self): self.payload.clear(); pos = 0
    def pop(self): self.pos += 1
    def pop_front(self): self.pos += 1; return self.payload[~-self.pos]

# internal_scc.py
class csr:
    def __init__(self, n: int, edges: list):
        from copy import deepcopy
        self.start = [0] * (n + 1)
        self.elist = [[] for _ in range(len(edges))]
        for e in edges:
            self.start[e[0] + 1] += 1
        for i in range(1, n + 1):
            self.start[i] += self.start[i - 1]
        counter = deepcopy(self.start)
        for e in edges:
            self.elist[counter[e[0]]] = e[1]; counter[e[0]] += 1

class scc_graph:
    # private
    edges = []
    
    # public
    def __init__(self, n: int):
        self._n = n
        self.now_ord = 0; self.group_num = 0
    
    def num_vertices(self): return self._n

    def add_edge(self, _from: int, _to: int): self.edges.append((_from, [_to]))
    
    def scc_ids(self):
        g = csr(self._n, self.edges)
        visited = []; low = [0] * self._n; ord = [-1] * self._n; ids = [0] * self._n
        
        def dfs(s, v: int):
            low[v] = ord[v] = self.now_ord; self.now_ord += 1
            visited.append(v)
            for i in range(g.start[v], g.start[v + 1]):
                to = g.elist[i][0]
                if ord[to] == -1:
                    s(s, to)
                    low[v] = min(low[v], low[to])
                else:
                    low[v] = min(low[v], ord[to])
            if low[v] == ord[v]:
                while True:
                    u = visited.pop()
                    ord[u] = self._n
                    ids[u] = self.group_num
                    if u == v: break
                self.group_num += 1

        for i in range(self._n):
            if ord[i] == -1: dfs(dfs, i)
        for i in range(self._n):
            ids[i] = self.group_num - 1 - ids[i]

        return (self.group_num, ids)
        
    def scc(self):
        ids = self.scc_ids()
        group_num = ids[0]
        counts = [0] * group_num
        for x in ids[1]: counts[x] += 1
        groups = [[] for _ in range(group_num)]
        for i in range(self._n):
            groups[ids[1][i]].append(i)
        return groups

# internal_type_traits.py 

# lazysegtree.py
'''
def op(l, r): return
def e(): return
def mapping(l, r): return
def composition(l, r): return
def id(): return 0
'''
class lazy_segtree:
    def __init__(self, op, e, mapping, composition, id, v: list):
        self.op = op; self.e = e; self.mapping = mapping; self.composition = composition; self.id = id
        self._n = len(v)
        self.log = ceil_pow2(self._n)
        self.size = 1 << self.log
        self.lz = [self.id()] * self.size
        self.d = [self.e()] * (2 * self.size)
        for i in range(self._n): self.d[self.size + i] = v[i]
        for i in range(self.size - 1, 0, -1): self.__update(i)

    def set_(self, p: int, x: int):
        assert 0 <= p and p < self._n
        p += self.size
        for i in range(self.log, 0, -1): self.__push(p >> i)
        self.d[p] = x
        for i in range(1, self.log + 1): self.__update(p >> 1)
        
    def get(self, p: int):
        assert 0 <= p and p < self._n
        p += self.size
        for i in range(self.log, 0, -1): self.__push(p >> i)
        return self.d[p]
    
    def prod(self, l: int, r: int):
        assert 0 <= l and l <= r and r <= self._n
        if l == r: return self.e()
        l += self.size; r += self.size

        for i in range(self.log, 0, -1):
            if ((l >> i) << i) != l: self.__push(l >> i)
            if ((r >> i) << i) != r: self.__push(r >> i)
            
        sml, smr = self.e(), self.e()
        while l < r:
            if l & 1: sml = self.op(sml, self.d[l]); l += 1
            if r & 1: r -= 1; smr = self.op(self.d[r], smr)
            l >>= 1; r >>= 1
        
        return self.op(sml, smr)
    
    def all_prod(self): return self.d[1]
    
    def apply(self, p: int, f):
        assert 0 <= p and p < self._n
        p += self.size
        for i in range(self.log, 0, -1): self.__push(p >> i)
        self.d[p] = self.mapping(f, self.d[p])
        for i in range(1, self.log + 1): self.__update(p >> 1)
    
    def apply(self, l: int, r: int, f):
        assert 0 <= l and l <= r and r <= self._n
        if l == r: return
        l += self.size; r += self.size

        for i in range(self.log, 0, -1):
            if ((l >> i) << i) != l: self.__push(l >> i)
            if ((r >> i) << i) != r: self.__push((r - 1) >> i)
            
        l2, r2 = l, r
        while l < r:
            if l & 1: self.__all_apply(l, f); l += 1
            if r & 1: r -= 1; self.__all_apply(r, f)
            l >>= 1; r >>= 1
        l, r = l2, r2
        
        for i in range(1, self.log + 1):
            if ((l >> i) << i) != l: self.__update(l >> i)
            if ((r >> i) << i) != r: self.__update(r >> i)
    
    def max_right(self, l: int, g):
        assert 0 <= l and l <= self._n
        if l == self._n: return self._n
        l += self.size
        for i in range(self.log, 0, -1): self.__push(l >> i)
        sm = self.e()
        while True:
            while l % 2 == 0: l >>= 1
            if not g(self.op(sm, self.d[l])):
                while l < self.size:
                    self.__push(l)
                    l = 2 * l
                    if g(self.op(sm, self.d[l])):
                        sm = self.op(sm, self.d[l])
                        l += 1
                return l - self.size
            sm = self.op(sm, self.d[l])
            l += 1
            if (l & -l) == l: break
        return self._n

    def min_left(self, r: int, g):
        assert 0 <= r and r <= self._n
        if r == 0: return 0
        r += self.size
        for i in range(self.log, 0, -1): self.__push(r >> i)
        sm = self.e()
        while True:
            r -= 1
            while r > 1 and r % 2: r >>= 1
            if not g(self.op(self.d[r], sm)):
                while r < self.size:
                    self.__push(r)
                    r = 2 * r + 1
                    if g(self.op(self.d[r], sm)):
                        sm = self.op(self.d[r], sm)
                        r -= 1
                return r + 1 - self.size
            sm = self.op(self.d[r], sm)
            if (r & -r) == r: break
        return 0

    # private
    def __update(self, k: int): self.d[k] = self.op(self.d[k * 2], self.d[k * 2 + 1])
    
    def __all_apply(self, k: int, f):
        self.d[k] = self.mapping(f, self.d[k])
        if k < self.size: self.lz[k] = self.composition(f, self.lz[k])
        
    def __push(self, k: int):
        self.__all_apply(2 * k, self.lz[k])
        self.__all_apply(2 * k + 1, self.lz[k])
        self.lz[k] = self.id()

# math
def pow_mod(x: int, n: int, m: int) -> int:
    assert 0 <= n and 1 <= m
    if m == 1: return 0
    bt = barrett(m)
    r = 1; y = safe_mod(x, m)
    while n:
        if n & 1: r = bt.mul(r, y)
        y = bt.mul(y, y)
        n >>= 1
    return n

def inv_mod(x: int, m: int) -> int:
    assert 1 <= m
    z = inv_gcd(x, m)
    assert z[0] == 1
    return z[1]

def crt(r: list, m: list) -> tuple:
    assert len(r) == len(m)
    n = len(r)
    r0 = 0; m0 = 1
    for i in range(n):
        assert 1 <= m[i]
        r1 = safe_mod(r[i], m[i]); m1 = m[i]
        if m0 < m1:
            r0, r1 = r1, r0
            m0, m1 = m1, m0
        if m0 % m1 == 0:
            if r0 % m1 != r1: return (0, 0)
            continue
        g, im = inv_gcd(m0, m1)
        u1 = m1 // g
        if (r1 - r0) % g: return (0, 0)
        x = (r1 - r0) // g % u1 * im % u1
        r0 += x * m0
        m0 *= u1
        if r0 < 0: r0 += m0
    return (r0, m0)

def floor_sum(n: int, m: int, a: int, b: int) -> int:
    ans = 0
    if a >= m:
        ans += (n - 1) * n * (a // m) // 2
        a %= m
    if b >= m:
        ans += n * (b // m)
        bb %= m
    y_max = (a * n + b) // m; x_max = (y_max * m - b)
    if y_max == 0: return ans
    ans += (n - (x_max + a - 1) // a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a)
    return ans

# maxflow.py
# from collections import deque
class mf_graph:
    numeric_limits_max = 10 ** 18
    def __init__(self, n: int):
        self._n = n
        self.g = [[] for _ in range(self._n)]
        self.pos = []
    
    def add_edge(self, _from: int, _to: int, cap: int) -> int:
        assert 0 <= _from and _from < self._n
        assert 0 <= _to and _to < self._n
        assert 0 <= cap
        m = len(self.pos)
        self.pos.append((_from, len(self.g[_from])))
        self.g[_from].append(self._edge(_to, len(self.g[_to]), cap))
        self.g[_to].append(self._edge(_from, len(self.g[_from]) - 1, 0))
        return m
    
    class edge:
        def __init__(s, _from: int, _to: int, cap: int, flow: int):
            s._from = _from; s._to = _to; s.cap = cap; s.flow = flow
    
    def get_edge(self, i: int) -> edge:
        m = len(self.pos)
        assert 0 <= i and i < m
        _e = self.g[self.pos[i][0]][self.pos[i][1]]
        _re = self.g[_e.to][_e.rev]
        return self.edge(self.pos[i][0], _e.to, _e.cap + _re.cap, _re.cap)
    
    def edges(self) -> list:
        m = len(self.pos)
        result = [self.get_edge(i) for i in range(m)]
        return result
    
    def change_edge(self, i: int, new_cap: int, new_flow: int):
        m = len(self.pos)
        assert 0 <= i and i < m
        assert 0 <= new_flow and new_flow <= new_cap
        _e = self.g[self.pos[i][0]][self.pos[i][1]]
        _re = self.g[_e.to][_e.rev]
        _e.cap = new_cap - new_flow
        _re.cap = new_flow
    
    def flow(self, s: int, t: int):
        return self.flow_(s, t, self.numeric_limits_max)

    def flow_(self, s: int, t: int, flow_limit: int) -> int:
        assert 0 <= s and s < self._n
        assert 0 <= t and t < self._n
        level = [0] * self._n; it = [0] * self._n
        
        def bfs():
            for i in range(self._n): level[i] = -1
            level[s] = 0
            que = deque([s])
            while que:
                v = que.popleft()
                for e in self.g[v]:
                    if e.cap == 0 or level[e.to] >= 0: continue
                    level[e.to] = level[v] + 1
                    if e.to == t: return    
                    que.append(e.to)

        def dfs(self_, v: int, up: int) -> int:
            if v == s: return up
            res = 0
            level_v = level[v]
            for i in range(it[v], len(self.g[v])):
                it[v] = i
                e = self.g[v][i]
                if level_v <= level[e.to] or self.g[e.to][e.rev].cap == 0: continue
                d = self_(self_, e.to, min(up - res, self.g[e.to][e.rev].cap))
                if d <= 0: continue
                self.g[v][i].cap += d
                self.g[e.to][e.rev].cap -= d
                res += d
                if res == up: break
            return res
        
        flow = 0
        while flow < flow_limit:
            bfs()
            if level[t] == -1: break
            for i in range(self._n): it[i] = 0
            while flow < flow_limit:
                f = dfs(dfs, t, flow_limit - flow)
                if not f: break
                flow += f
        return flow
    
    def min_cut(self, s: int) -> list:
        visited = [False] * self._n
        que = deque([s])
        while que:
            p = que.popleft()
            visited[p] = True
            for e in self.g[p]:
                if e.cap and not visited[e.to]:
                    visited[e.to] = True
                    que.append(e.to)
        return visited

    class _edge:
        def __init__(s, to: int, rev: int, cap: int):
            s.to = to; s.rev = rev; s.cap = cap

# mincostflow.py
# from heapq import heappop, heappush
class mcf_graph:
    numeric_limits_max = 10 ** 18

    def __init__(self, n: int):
        self._n = n
        self.g = [[] for _ in range(n)]
        self.pos = []

    def add_edge(self, _from: int, _to: int, cap: int, cost: int) -> int:
        assert 0 <= _from and _from < self._n
        assert 0 <= _to and _to < self._n
        m = len(self.pos)
        self.pos.append((_from, len(self.g[_from])))
        self.g[_from].append(self._edge(_to, len(self.g[_to]), cap, cost))
        self.g[_to].append(self._edge(_from, len(self.g[_from]) - 1, 0, -cost))
        return m
    
    class edge:
        def __init__(s, _from: int, _to: int, cap: int, flow: int, cost: int):
            s._from = _from; s._to = _to; s.cap = cap; s.flow = flow; s.cost = cost
    
    def get_edge(self, i: int) -> edge:
        m = len(self.pos)
        assert 0 <= i and i < m
        _e = self.g[self.pos[i][0]][self.pos[i][1]]
        _re = self.g[_e.to][_e.rev]
        return self.edge(self.pos[i][0], _e.to, _e.cap + _re.cap, _re.cap, _e.cost)
    
    def edges(self) -> list:
        m = len(self.pos)
        result = [self.get_edge(i) for i in range(m)]
        return result
    
    def flow(self, s: int, t: int) -> edge:
        return self.flow_(s, t, self.numeric_limits_max)
    def flow_(self, s: int, t: int, flow_limit: int) -> edge:
        return self.__slope(s, t, flow_limit)[-1]
    
    def slope(self, s: int, t: int) -> list:
        return self.slope_(s, t, self.numeric_limits_max)
    def slope_(self, s: int, t: int, flow_limit: int) -> list:
        return self.__slope(s, t, flow_limit)
    
    def __slope(self, s: int, t: int, flow_limit: int) -> list:
        assert 0 <= s and s < self._n
        assert 0 <= t and t < self._n
        assert s != t
        dual = [0] * self._n; dist = [0] * self._n
        pv, pe = [-1] * self._n, [-1] * self._n
        vis = [False] * self._n
        
        def dual_ref():
            for i in range(self._n):
                dist[i] = self.numeric_limits_max
                pv[i] = -1
                pe[i] = -1
                vis[i] = False
            class Q:
                def __init__(s, key: int, to: int):
                    s.key = key; s.to = to
                def __lt__(s, r): return s.key < r.key
            que = []
            dist[s] = 0
            heappush(que, Q(0, s))
            while que:
                v = heappop(que).to
                if vis[v]: continue
                vis[v] = True
                if v == t: break
                for i in range(len(self.g[v])):
                    e = self.g[v][i]
                    if vis[e.to] or not e.cap: continue
                    cost = e.cost - dual[e.to] + dual[v]
                    if dist[e.to] - dist[v] > cost:
                        dist[e.to] = dist[v] + cost
                        pv[e.to] = v
                        pe[e.to] = i
                        heappush(que, Q(dist[e.to], e.to))
            if not vis[t]: return False
            for v in range(self._n):
                if not vis[v]: continue
                dual[v] -= dist[t] - dist[v]
            return True

        flow = 0
        cost = 0; prev_cost = -1
        result = []
        result.append((flow, cost))
        while flow < flow_limit:
            if not dual_ref(): break
            c = flow_limit - flow
            v = t
            while v != s:
                c = min(c, self.g[pv[v]][pe[v]].cap)
                v = pv[v]
            v = t
            while v != s:
                e = self.g[pv[v]][pe[v]]
                e.cap -= c
                self.g[v][e.rev].cap += c
                v = pv[v]
            d = -dual[s]
            flow += c
            cost += c * d
            if prev_cost == d:
                result.pop()
            result.append((flow, cost))
            prev_cost = cost
        return result
    class _edge:
        def __init__(s, to: int, rev: int, cap: int, cost: int):
            s.to = to; s.rev = rev; s.cap = cap; s.cost = cost

# modint.py 
class Mint:
    modint1000000007 = 1000000007
    modint998244353 = 998244353

    def __init__(self, v: int = 0):
        self.m = self.modint1000000007
        # self.m = self.modint998244353
        self.x = v % self.__umod()
    
    def inv(self):
        if is_prime_constexpr(self.__umod()):
            assert self.x
            return self.pow_(self.__umod() - 2)
        else:
            eg = inv_gcd(self.x, self.m)
            assert eg[0] == 1
            return eg[2]

    def __str__(self): return str(self.x)
    def __le__(self, other): return self.x <= Mint.__get_val(other)
    def __lt__(self, other): return self.x < Mint.__get_val(other)
    def __ge__(self, other): return self.x >= Mint.__get_val(other)
    def __gt(self, other): return self.x > Mint.__get_val(other)
    def __eq__(self, other): return self.x == Mint.__get_val(other)
    
    def __iadd__(self, other):
        self.x += Mint.__get_val(other)
        if self.x >= self.__umod(): self.x -= self.__umod()
        return self
    def __add__(self, other):
        _v = Mint(self.x); _v += other
        return _v

    def __isub__(self, other):
        self.x -= Mint.__get_val(other)
        if self.x >= self.__umod(): self.x += self.__umod()
        return self
    def __sub__(self, other):
        _v = Mint(self.x); _v -= other
        return _v
    def __rsub__(self, other):
        _v = Mint(Mint.__get_val(other)); _v -= self
        return _v
    
    def __imul__(self, other):
        self.x =self.x * Mint.__get_val(other) % self.__umod()
        return self
    def __mul__(self, other):
        _v = Mint(self.x); _v *= other
        return _v

    def __itruediv__(self, other):
        self.x = self.x / Mint.__get_val(other) % self.__umod()
        return self
    def __truediv__(self, other):
        _v = Mint(self.x); _v /= other
        return _v
    def __rtruediv__(self, other):
        _v = Mint(Mint.__get_val(other)); _v /= self
        return _v
    
    def __ifloordiv__(self, other):
        other = other if isinstance(other, Mint) else Mint(other)
        self *= other.inv()
        return self
    def __floordiv__(self, other):
        _v = Mint(self.x); _v //= other
        return _v
    def __rfloordiv__(self, other):
        _v = Mint(Mint.__get_val(other)); _v //= self
        return _v

    def __pow__(self, other):
        _v = Mint(pow(self.x, Mint.__get_val(other), self.__umod()))
        return _v
    def __rpow__(self, other):
        _v = Mint(pow(Mint.__get_val(other), self.x, self.__umod()))
        return _v

    def __imod__(self, other):
        self.x %= Mint.__get_val(other)
        return self
    def __mod__(self, other):
        _v = Mint(self.x); _v %= other
        return _v
    def __rmod__(self, other):
        _v = Mint(Mint.__get_val(other)); _v %= self
        return _v

    def __ilshift__(self, other):
        self.x <<= Mint.__get_val(other)
        return self
    def __irshift__(self, other):
        self.x >>= Mint.__get_val(other)
        return self
    def __lshift__(self, other):
        _v = Mint(self.x); _v <<= other
        return _v
    def __rshift__(self, other):
        _v = Mint(self.x); _v >>= other
        return _v
    def __rlshift__(self, other):
        _v = Mint(Mint.__get_val(other)); _v <<= self
        return _v
    def __rrshift__(self, other):
        _v = Mint(Mint.__get_val(other)); _v >>= self
        return _v
    
    __repr__ = __str__
    __radd__ = __add__
    __rmul__ = __mul__

    def __umod(self): return self.m
    
    @staticmethod
    def __get_val(val): return val.x if isinstance(val, Mint) else val
 
    def pow_(self, n: int):
        assert 0 <= n
        x = Mint(self.x); r = 1
        while n:
            if n & 1: r *= x
            x *= x
            n >>= 1
        return r
    def val(self): return self.x
    def mod(self): return self.m
    def raw(self, v):
        x = Mint()
        x.x = v
        return x

# scc.py
class scc_graph_sub:
    # public
    def __init__(self, n):
        self.internal = scc_graph(n)
    
    def add_edge(self, _from, _to):
        n = self.internal.num_vertices()
        assert 0 <= _from and _from < n
        assert 0 <= _to and _to < n
        self.internal.add_edge(_from, _to)
    
    def scc(self): return self.internal.scc()
    
# segtree.py
'''
def e(): return
def op(l, r): return
def f(): return
'''
class segtree:
    def __init__(self, op, e, v: list):
        self._n = len(v)
        self.log = ceil_pow2(self._n)
        self.size = 1 << self.log
        self.op = op; self.e = e
        self.d = [self.e()] * (self.size * 2)
        for i in range(self._n): self.d[self.size + i] = v[i]
        for i in range(self.size - 1, 0, -1): self.__update(i)
    
    def set_(self, p: int, x: int):
        assert 0 <= p and p < self._n
        p += self.size
        self.d[p] = x
        for i in range(1, self.log + 1): self.__update(p >> i)
    
    def get(self, p: int):
        assert 0 <= p and p < self._n
        return self.d[p + self.size]

    def prod(self, l: int, r: int):
        assert 0 <= l and l <= r and r <= self._n
        l += self.size; r += self.size
        sml, smr = self.e(), self.e()
        while l < r:
            if l & 1: sml = self.op(sml, self.d[l]); l += 1
            if r & 1: r -= 1; smr = self.op(self.d[r], smr)
            l >>= 1; r >>= 1
        return self.op(sml, smr)

    def all_prod(self): return self.d[1]

    def max_right(self, l: int, f):
        assert 0 <= l and l <= self._n
        assert f(self.e())
        if l == self._n: return self._n
        l += self.size
        sm = self.e()
        while True:
            while l % 2 == 0: l >>= 1
            if not f(self.op(sm, self.d[l])):
                while l < self.size:
                    l = 2 * l
                    if f(self.op(sm, self.d[l])):
                        sm = self.op(sm, self.d[l])
                        l += 1
                return l - self.size
            sm = self.op(sm, self.d[l])
            l += 1
            if (l & -l) == l: break
        return self._n
    
    def min_left(self, r: int, f):
        assert 0 <= r and r <= self._n
        assert f(self.e())
        if r == 0: return 0
        r += self.size
        sm = self.e()
        while True:
            r -= 1
            while r > 1 and r % 2: r >>= 1
            if not f(self.op(self.d[r], sm)):
                while r < self.size:
                    r = 2 * r + 1
                    if f(self.op(self.d[r], sm)):
                        sm = self.op(self.d[r], sm)
                        r -= 1
                return r + 1 - self.size
            sm = self.op(self.d[r], sm)
            if (r & -r) == r: break
        return 0

    def __update(self, k: int): self.d[k] = self.op(self.d[k * 2], self.d[k * 2 + 1])

# string.py
def sa_native(s: list):
    from functools import cmp_to_key
    def mycmp(r, l):
        if l == r: return -1
        while l < n and r < n:
            if s[l] != s[r]: return 1 if s[l] < s[r] else -1
            l += 1
            r += 1
        return 1 if l == n else -1
    n = len(s)
    sa = [i for i in range(n)]
    sa.sort(key=cmp_to_key(mycmp))
    return sa

def sa_doubling(s: list):
    from functools import cmp_to_key
    def mycmp(y, x):
        if rnk[x] != rnk[y]: return 1 if rnk[x] < rnk[y] else -1
        rx = rnk[x + k] if x + k < n else - 1
        ry = rnk[y + k] if y + k < n else - 1
        return 1 if rx < ry else -1
        
    n = len(s)
    sa = [i for i in range(n)]; rnk = s; tmp = [0] * n; k = 1
    while k < n:
        sa.sort(key=cmp_to_key(mycmp))
        tmp[sa[0]] = 0
        for i in range(1, n):
            tmp[sa[i]] = tmp[sa[i - 1]]
            if mycmp(sa[i], sa[i - 1]): tmp[sa[i]] += 1
        tmp, rnk = rnk, tmp
        k *= 2
    return sa

def sa_is(s: list, upper: int):
    THRESHOLD_NATIVE = 10
    THRESHOLD_DOUBLING = 40
    n = len(s)
    if n == 0: return []
    if n == 1: return [0]
    if n == 2:
        if s[0] < s[1]:
            return [0, 1]
        else:
            return [1, 0]
    if n < THRESHOLD_NATIVE:
        return sa_native(s)
    if n < THRESHOLD_DOUBLING:
        return sa_doubling(s)
    
    sa = [0] * n
    ls = [False] * n
    for i in range(n - 2, -1, -1):
        ls[i] = ls[i + 1] if s[i] == s[i + 1] else s[i] < s[i + 1]
    
    sum_l = [0] * (upper + 1); sum_s = [0] * (upper + 1)
    for i in range(n):
        if not ls[i]:
            sum_s[s[i]] += 1
        else:
            sum_l[s[i] + 1] += 1
    for i in range(upper + 1):
        sum_s[i] += sum_l[i]
        if i < upper: sum_l[i + 1] += sum_s[i]
        
    def induce(lms: list):
        from copy import copy
        for i in range(n): sa[i] = -1
        buf = copy(sum_s)
        for d in lms:
            if d == n: continue
            sa[buf[s[d]]] = d; buf[s[d]] += 1
        
        buf = copy(sum_l)
        sa[buf[s[n - 1]]] = n - 1; buf[s[n - 1]] += 1
        for i in range(n):
            v = sa[i]
            if v >= 1 and not ls[v - 1]:
                sa[buf[s[v - 1]]] = v - 1; buf[s[v - 1]] += 1
        
        buf = copy(sum_l)
        for i in range(n - 1, -1, -1):
            v = sa[i]
            if v >= 1 and ls[v - 1]:
                buf[s[v - 1] + 1] -= 1; sa[buf[s[v - 1] + 1]] = v - 1

    lms_map = [-1] * (n + 1)
    m = 0
    for i in range(1, n):
        if not ls[i - 1] and ls[i]:
            lms_map[i] = m; m += 1
    
    lms = [i for i in range(1, n) if not ls[i - 1] and ls[i]]
    induce(lms)

    if m:
        sorted_lms = [v for v in sa if lms_map[v] != -1]
        rec_s = [0] * m
        rec_upper = 0
        rec_s[lms_map[sorted_lms[0]]] = 0
        for i in range(1, m):
            l = sorted_lms[i - 1]; r = sorted_lms[i]
            end_l = lms[lms_map[l] + 1] if lms_map[l] + 1 < m else n
            end_r = lms[lms_map[r] + 1] if lms_map[r] + 1 < m else n
            same = True
            if end_l - l != end_r - r:
                same = False
            else:
                while l < end_l:
                    if s[l] != s[r]: break
                    l += 1
                    r += 1
                if l == n or s[l] != s[r]: same = False
            if not same: rec_upper += 1
            rec_s[lms_map[sorted_lms[i]]] = rec_upper
        
        rec_sa = sa_is(rec_s, rec_upper)

        for i in range(m):
            sorted_lms[i] = lms[rec_sa[i]]
        induce(sorted_lms)
    return sa

def suffix_array(s: list, upper: int):
    assert 0 <= upper
    for d in s:
        assert 0 <= d and d <= upper
    sa = sa_is(s, upper)
    return sa

def suffix_array2(s: list):
    from functools import cmp_to_key
    n = len(s)
    idx = [i for i in range(n)]
    idx.sort(key=cmp_to_key(lambda l, r: s[l] < s[r]))
    s2 = [0] * n
    now = 0
    for i in range(n):
        if i and s[idx[i - 1]] != s[idx[i]]: now += 1
        s2[idx[i]] = now
    return sa_is(s2, now)

def suffix_array3(s: str):
    n = len(s)
    s2 = list(map(ord, s))
    return sa_is(s2, 255)

def lcp_array(s: list, sa: list):
    n = len(s)
    assert n >= 1
    rnk = [0] * n
    for i in range(n):
        rnk[sa[i]] = i
    lcp = [0] * (n - 1)
    h = 0
    for i in range(n):
        if h > 0: h -= 1
        if rnk[i] == 0: continue
        j = sa[rnk[i] - 1]
        while j + h < n and i + h < n:
            if s[j + h] != s[i + h]: break
            h += 1
        lcp[rnk[i] - 1] = h
    return lcp

def lcp_array2(s: str, sa: list):
    n = len(s)
    s2 = list(map(ord, s))
    return lcp_array(s2, sa)

def z_algorithm(s: list):
    n = len(s)
    if n == 0: return []
    z = [-1] * n
    z[0] = 0; j = 0
    for i in range(1, n):
        k = z[i] = 0 if j + z[j] <= i else min(j + z[j] - i, z[i - j])
        while i + k < n and s[k] == s[i + k]: k += 1
        z[i] = k
        if j + z[j] < i + z[i]: j = i
    z[0] = n
    return z

def z_algorithm2(s: str):
    n = len(s)
    s2 = list(map(ord, s))
    return z_algorithm(s2)

# twosat.py
class two_sat:
    def __init__(self, n: int):
        self._n = n
        self.scc = scc_graph(2 * n)
        self._answer = [False] * n
    
    def add_clause(self, i: int, f: bool, j: int, g: bool):
        assert 0 <= i and i < self._n
        assert 0 <= j and j < self._n
        self.scc.add_edge(2 * i + (not f), 2 * j + g)
        self.scc.add_edge(2 * j + (not g), 2 * i + f)
        
    def satisfiable(self) -> bool:
        _id = self.scc.scc_ids()[1]
        for i in range(self._n):
            if _id[2 * i] == _id[2 * i + 1]: return False
            self._answer[i] = _id[2 * i] < _id[2 * i + 1]
        return True
    
    def answer(self): return self._answer

# --------------------<< Library End >>-------------------- #

import sys

sys.setrecursionlimit(10 ** 6)
MOD = 10 ** 9 + 7
INF = 10 ** 9
PI = 3.14159265358979323846

def read_str():      return sys.stdin.readline().strip()
def read_int():      return int(sys.stdin.readline().strip())
def read_ints():     return map(int, sys.stdin.readline().strip().split())
def read_ints2(x):   return map(lambda num: int(num) - x, sys.stdin.readline().strip().split())
def read_str_list(): return list(sys.stdin.readline().strip().split())
def read_int_list(): return list(map(int, sys.stdin.readline().strip().split()))
def GCD(a: int, b: int) -> int: return b if a%b==0 else GCD(b, a%b)
def LCM(a: int, b: int) -> int: return (a * b) // GCD(a, b)

def Main_A():
    n, q = read_ints()
    d = dsu(n)
    for _ in range(q):
        t, u, v = read_ints()
        if t == 0:
            d.merge(u, v)
        else:
            print(int(d.same(u, v)))

def Main_B():
    n, q = read_ints()
    a = read_int_list()
    fw = fenwick_tree(n)
    for i, x in enumerate(a):
        fw.add(i, x)
    for _ in range(q):
        query = read_int_list()
        if query[0] == 0:
            fw.add(query[1], query[2])
        else:
            print(fw.sum(query[1], query[2]))

def Main_C():
    for _ in range(read_int()):
        n, m, a, b = read_ints()
        print(floor_sum(n, m, a, b))

from collections import deque
def Main_D():
    n, m = read_ints()
    grid = [list(read_str()) for _ in range(n)]
    mf = mf_graph(n * m + 2)
    start = n * m
    end = start + 1
    dir = [(1, 0), (0, 1)]
    
    for y in range(n):
        for x in range(m):
            if (y + x) % 2 == 0:
                mf.add_edge(start, m*y + x, 1)
            else:
                mf.add_edge(m*y + x, end, 1)
            
            if grid[y][x] == '.':
                for dy, dx in dir:
                    ny = y + dy; nx = x + dx
                    if ny < n and nx < m and grid[ny][nx] == '.':
                        f, t = y*m + x, ny*m + nx
                        if (y + x) % 2: f, t = t, f
                        mf.add_edge(f, t, 1)

    ans = mf.flow(start, end)
    for y in range(n):
        for x in range(m):
            for e in mf.g[y * m + x]:
                to, rev, cap = e.to, e.rev, e.cap
                ny, nx = divmod(to, m)
                if (y + x) % 2 == 0 and cap == 0 and to != start and to != end and (y*m+x) != start and (y*m+x) != end:
                    if y + 1 == ny: grid[y][x] = 'v'; grid[ny][nx] = '^'
                    elif y == ny + 1: grid[y][x] = '^'; grid[ny][nx] = 'v'
                    elif x + 1 == nx: grid[y][x] = '>'; grid[ny][nx] = '<'
                    elif x == nx + 1: grid[y][x] = '<'; grid[ny][nx] = '>'
                        
    print(ans)
    print(*[''.join(ret) for ret in grid], sep='\n')

#from heapq import heappop, heappush
def Main_E():
    n, k = read_ints()
    a = [read_int_list() for _ in range(n)]
    mcf = mcf_graph(n * 2 + 2)
    s = n * 2
    t = n * 2 + 1
 
    for i in range(n):
        mcf.add_edge(s, i, k, 0)
        mcf.add_edge(i + n, t, k, 0)
    mcf.add_edge(s, t, n * k, INF)
    
    for i in range(n):
        for j in range(n):
            mcf.add_edge(i, n + j, 1, INF - a[i][j])
    
    result = mcf.flow_(s, t, n * k)
    print(n * k * INF - result[1])
    grid = [['.'] * n for _ in range(n)]
    edges = mcf.edges()
    for e in edges:
        if e._from == s or e._to == t or e.flow == 0: continue
        grid[e._from][e._to - n] = 'X'
    print(*[''.join(g) for g in grid], sep='\n')

def Main_F():
    MOD = 998244353
    n, m = read_ints()
    a = read_int_list()
    b = read_int_list()
    a = [x % MOD for x in a]
    b = [x % MOD for x in b]
    cnv = convolution(a,b,MOD)
    ans = cnv.convolution()
    print(*ans)

def Main_G():
    sys.setrecursionlimit(10 ** 6)
    n, m = read_ints()
    scc = scc_graph(n)
    for _ in range(m):
        a, b = read_ints()
        scc.add_edge(a, b)
    ans = scc.scc()
    print(len(ans))
    for v in ans:
        print(len(v), ' '.join(map(str, v[::-1])))

def Main_H():
    n, d = read_ints()
    xy = [read_int_list() for _ in range(n)]
    tw = two_sat(n)
    
    for i in range(n):
        for j in range(i + 1, n):
            for x in range(2):
                if abs(xy[i][0] - xy[j][0]) < d: tw.add_clause(i, False, j, False)
                if abs(xy[i][0] - xy[j][1]) < d: tw.add_clause(i, False, j, True)
                if abs(xy[i][1] - xy[j][0]) < d: tw.add_clause(i, True, j, False)
                if abs(xy[i][1] - xy[j][1]) < d: tw.add_clause(i, True, j, True)
                
    if not tw.satisfiable():
        print('No')
        exit()
    print('Yes')
    ans = tw.answer()
    for i, flag in enumerate(ans):
        print(xy[i][0] if flag else xy[i][1])

def Main_I():
    s = read_str()
    sa = suffix_array3(s)
    ans = len(s) * (len(s) + 1) // 2
    for x in lcp_array2(s, sa):
        ans -= x
    print(ans)

def Main_J():
    def op(l, r): return max(l, r)
    def e(): return -1
    def f(n): return n < r
    n, q = read_ints()
    a = read_int_list()
    seg = segtree(op, e, a)
    query = [(read_ints()) for _ in range(q)]
    for i in range(q):
        t, l, r = query[i]
        if t == 1:
            seg.set_(~-l, r)
        elif t == 2:
            print(seg.prod(~-l, r))
        else:
            print(seg.max_right(~-l, f) + 1)

def Main_K():
    p = 998244353
    def op(l, r):
        l1, l2 = l >> 32, l % (1 << 32)
        r1, r2 = r >> 32, r % (1 << 32)    
        return (((l1 + r1) % p) << 32) + l2 + r2
    def e(): return 0
    def mapping(l, r):
        l1, l2 = l >> 32, l % (1 << 32)
        r1, r2 = r >> 32, r % (1 << 32)
        return (((l1 * r1 + l2 * r2) % p) << 32) + r2
    def composition(l, r):
        l1, l2 = l >> 32, l % (1 << 32)
        r1, r2 = r >> 32, r % (1 << 32)
        return ((l1 * r1 % p) << 32) + (l1 * r2 + l2) % p
    def id(): return 1 << 32
    n, q = read_ints()
    A = read_int_list()
    A = [(x << 32) + 1 for x in A]
    
    seg = lazy_segtree(op, e, mapping, composition, id, A)
    ans = []
    for _ in range(q):
        query = read_int_list()
        if query[0] == 0:
            l, r, b, c = query[1:]
            seg.apply(l, r, (b << 32) + c)
        else:
            l, r = query[1:]
            print(seg.prod(l, r) >> 32)

def Main_L():
    def op(l: tuple, r: tuple): return (l[0] + r[0], l[1] + r[1], l[2] + r[2] + l[1] * r[0])
    def e(): return (0, 0, 0)
    def mapping(l:bool, r: tuple):
        if not l: return r
        return (r[1], r[0], r[1] * r[0] - r[2])
    def composition(l: bool, r: bool): return l ^ r
    def id(): return False
    n, q = read_ints()
    A = read_int_list()
    query = [(read_ints()) for _ in range(q)]
    
    a = [(1, 0, 0) if i == 0 else (0, 1, 0) for i in A]
    seg = lazy_segtree(op, e, mapping, composition, id, a)
 
    for t, l, r in query:
        if t == 1:
            seg.apply(~-l, r, True)
        else:
            print(seg.prod(~-l, r)[2])

if __name__ == '__main__':
    Main_D()