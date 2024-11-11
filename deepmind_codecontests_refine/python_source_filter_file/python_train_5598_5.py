class lazySegTree:
  #遅延評価セグメント木
  def __init__(s, op, e, mapping, composition, id, v):
    if type(v) is int: v = [e()] * v
    s._n = len(v)
    s.log = s.ceil_pow2(s._n)
    s.size = 1 << s.log
    s.d = [e()] * (2 * s.size)
    s.lz = [id()] * s.size
    s.e = e
    s.op = op
    s.mapping = mapping
    s.composition = composition
    s.id = id
    for i in range(s._n): s.d[s.size + i] = v[i]
    for i in range(s.size - 1, 0, -1): s.update(i)
  
  # 1点更新
  def set(s, p, x):
    p += s.size
    for i in range(s.log, 0, -1): s.push(p >> i)
    s.d[p] = x
    for i in range(1, s.log + 1): s.update(p >> i)
 
  # 1点取得
  def get(s, p):
    p += s.size
    for i in range(s.log, 0, -1): s.push(p >> i)
    return s.d[p]
 
  # 区間演算
  def prod(s, l, r):
    if l == r: return s.e()
    l += s.size
    r += s.size
    for i in range(s.log, 0, -1):
      if (((l >> i) << i) != l): s.push(l >> i)
      if (((r >> i) << i) != r): s.push(r >> i)
    sml, smr = s.e(), s.e()
    while (l < r):
      if l & 1: 
        sml = s.op(sml, s.d[l])
        l += 1
      if r & 1:
        r -= 1
        smr = s.op(s.d[r], smr)
      l >>= 1
      r >>= 1
    return s.op(sml, smr)
 
  # 全体演算
  def all_prod(s): return s.d[1]
 
  # 1点写像
  def apply(s, p, f):
    p += s.size
    for i in range(s.log, 0, -1): s.push(p >> i)
    s.d[p] = s.mapping(f, s.d[p])
    for i in range(1, s.log + 1): s.update(p >> i)
 
  # 区間写像
  def apply(s, l, r, f):
    if l == r: return
    l += s.size
    r += s.size
    for i in range(s.log, 0, -1):
      if (((l >> i) << i) != l): s.push(l >> i)
      if (((r >> i) << i) != r): s.push((r - 1) >> i)
    l2, r2 = l, r
    while l < r:
      if l & 1: 
        sml = s.all_apply(l, f)
        l += 1
      if r & 1:
        r -= 1
        smr = s.all_apply(r, f)
      l >>= 1
      r >>= 1
    l, r = l2, r2
    for i in range(1, s.log + 1):
      if (((l >> i) << i) != l): s.update(l >> i)
      if (((r >> i) << i) != r): s.update((r - 1) >> i)
   
  # L固定時の最長区間のR
  def max_right(s, l, g):
    if l == s._n: return s._n
    l += s.size
    for i in range(s.log, 0, -1): s.push(l >> i)
    sm = s.e()
    while True:
      while (l % 2 == 0): l >>= 1
      if not g(s.op(sm, s.d[l])):
        while l < s.size:
          s.push(l)
          l = 2 * l
          if g(s.op(sm, s.d[l])):
            sm = s.op(sm, s.d[l])
            l += 1
        return l - s.size
      sm = s.op(sm, s.d[l])
      l += 1
      if (l & -l) == l: break
    return s._n
 
  # R固定時の最長区間のL
  def min_left(s, r, g):
    if r == 0: return 0
    r += s.size
    for i in range(s.log, 0, -1): s.push((r - 1) >> i)
    sm = s.e()
    while True:
      r -= 1
      while r > 1 and (r % 2): r >>= 1
      if not g(s.op(s.d[r], sm)):
        while r < s.size:
          s.push(r)
          r = 2 * r + 1
          if g(s.op(s.d[r], sm)):
            sm = s.op(s.d[r], sm)
            r -= 1
        return r + 1 - s.size
      sm = s.op(s.d[r], sm)
      if (r & - r) == r: break
    return 0
 
  def update(s, k): s.d[k] = s.op(s.d[2 * k], s.d[2 * k + 1])
  def all_apply(s, k, f):
    s.d[k] = s.mapping(f, s.d[k])
    if k < s.size: s.lz[k] = s.composition(f, s.lz[k])
  def push(s, k):
    s.all_apply(2 * k, s.lz[k])
    s.all_apply(2 * k + 1, s.lz[k])
    s.lz[k] = s.id()
  def ceil_pow2(s, n):
    x = 0
    while (1 << x) < n: x += 1
    return x

# return a・e = a となる e
def e():
  return 0

# return a・b
def op(a, b):
  a0, a1 = a >> 18, a & ((1 << 18) - 1)
  b0, b1 = b >> 18, b & ((1 << 18) - 1)
  return (((a0 * pow(10, b1) + b0) % MOD) << 18) + a1 + b1

# return f(a)
def mapping(f, a):
  if f == 0: return a
  a0, a1 = a >> 18, a & ((1 << 18) - 1)
  return (D[f][a1] << 18) + a1

# return f・g
# gを写像した後にfを写像した結果
def composition(f, g):
  if f == 0: return g
  return f

# return f(id) = id となる id
def id():
  return 0

N, Q = list(map(int, input().split()))
LRD = [list(map(int, input().split())) for _ in range(Q)]
MOD = 998244353

D = [[0]]
for i in range(1, 10):
  D.append([0])
  for j in range(N):
    D[i].append((D[i][-1] * 10 + i) % MOD)

a = [(1 << 18) + 1 for _ in range(N)]
seg = lazySegTree(op, e, mapping, composition, id, a)
for l, r, d in LRD:
  seg.apply(l - 1, r, d)
  ans = seg.all_prod()
  print(ans >> 18)

