class segtree:
  #セグメント木
  def __init__(s, v, op, e):
    s._n = len(v)
    s.log = s.ceil_pow2(s._n)
    s.size = 1 << s.log
    s.d = [e()] * (2 * s.size)
    s.e = e
    s.op = op
    for i in range(s._n): s.d[s.size + i] = v[i]
    for i in range(s.size - 1, 0, -1): s.update(i)
  
  # 1点更新
  def set(s, p, x):
    p += s.size
    s.d[p] = x
    for i in range(1, s.log + 1): s.update(p >> i)
 
  # 1点取得
  def get(s, p):
    return s.d[p + s.size]
 
  # 区間演算
  def prod(s, l, r):
    sml, smr = s.e(), s.e()
    l += s.size
    r += s.size
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
 
  # L固定時の最長区間のR
  def max_right(s, l, g):
    if l == s._n: return s._n
    l += s.size
    sm = s.e()
    while True:
      while (l % 2 == 0): l >>= 1
      if not g(s.op(sm, s.d[l])):
        while l < s.size:
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
    sm = s.e()
    while True:
      r -= 1
      while r > 1 and (r % 2): r >>= 1
      if not g(s.op(s.d[r], sm)):
        while r < s.size:
          r = 2 * r + 1
          if g(s.op(s.d[r], sm)):
            sm = s.op(s.d[r], sm)
            r -= 1
        return r + 1 - s.size
      sm = s.op(s.d[r], sm)
      if (r & - r) == r: break
    return 0
 
  def update(s, k): s.d[k] = s.op(s.d[2 * k], s.d[2 * k + 1])
  def ceil_pow2(s, n):
    x = 0
    while (1 << x) < n: x += 1
    return x
 
import sys
    
def e():
  return 0
 
def op(s, t):
  return max(s, t)
 
N, Q = list(map(int, input().split()))
A = list(map(int, input().split()))
Query = [list(map(int, input().split())) for _ in range(Q)]

seg = segtree(A, op, e)

for q in Query:
  if q[0] == 1:
    _, x, v = q
    seg.set(x - 1 , v)
  elif q[0] == 2:
    _, l, r = q
    print(seg.prod(l - 1, r))
  elif q[0] == 3:
    _, x, v = q
    def g(n):
      return n < v
    print(seg.max_right(x, g) + 1)