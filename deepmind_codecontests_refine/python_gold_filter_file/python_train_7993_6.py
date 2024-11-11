def nCr(n_, r_, m_):
  c = min(r_ , n_ - r_)
  bunshi = 1
  bunbo = 1
  for i in range(1,c+1):
    bunshi = bunshi * (n_+1-i) % m_
    bunbo = bunbo * i % m_
  return bunshi * pow(bunbo, m_-2, m_) % m_


x,y = map(int,input().split())
s = max(x,y)
t = min(x,y)
u = 2*t-s
if u%3 != 0 or u < 0:
  print(0)
else:
  a = u//3
  b = a + s - t
  ans = nCr(a+b,b,10**9+7)
  print(ans)