class BIT:
  def __init__(self,n):
    self.N = n
    self.data = [0]*(N+1)
  def bit_add(self,i,a):
    j = i+1
    while j<=N:
      self.data[j] += a
      j += j&-j
  def bit_sum(self,i):
    m = 0
    j = i+1
    while j>0:
      m += self.data[j]
      j -= j&-j
    return m
  def bit_search(self,x):
    i = 0
    m = 0
    j = 1<<(self.N.bit_length()-1)
    while j:
      if i+j<=N and self.data[i+j]+m<=x:
        i += j
        m += self.data[i]
      j >>= 1
    return i
N, *A = map(int, open(0).read().split())
bit = BIT(N)
ntoi = [0]*(N+1)
ans = 0
for i, a in enumerate(A):
  ntoi[a] = i
for i in range(1,N+1):
  j = ntoi[i]
  L = bit.bit_sum(j)
  R = N-L-1
  if L!=0:
    a = bit.bit_search(L-1)
  else:
    a = -1
  if R!=0:
    b = bit.bit_search(L)
  else:
    b = N
  ans += (j-a)*(b-j)*i
  bit.bit_add(j,1)
print(ans)