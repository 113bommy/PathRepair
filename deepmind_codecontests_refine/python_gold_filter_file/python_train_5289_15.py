# 解説放送の方針
# 平面走査をし、各点について、左上、左下、右上、右下にある点を数え、計算する。
# 解説放送ではBITを2本使っていたが、座標圧縮の結果を利用してBIT１本で済むようにした

N = int(input())
xy = [tuple(map(int,input().split())) for _ in range(N)]

mod = 998244353

class BIT:
    '''https://tjkendev.github.io/procon-library/python/range_query/bit.html'''
    def __init__(self, n):
        self.n = n
        self.data = [0]*(n+1)
        self.el = [0]*(n+1)
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s
    def add(self, i, x):
        self.el[i] += x
        while i <= self.n:
            self.data[i] += x
            i += i & -i
    def query(self, i, j=None):
        if j is None:
            return self.el[i]
        return self.sum(j) - self.sum(i)

# 平面走査のためのソート（高速化のため１次元にしてソート）
xy2 = []
for i in range(N):
  x,y = xy[i]
  x += 10**9
  y += 10**9
  xy2.append(y<<80 | x << 40 | i)

# ソート後の復元+座標圧縮用の辞書作成
# 座標圧縮: 小さいyから順に1,2,3...と値を割り振る。
xy2 = sorted(xy2)
mask = (1<<40)-1
y_order=[0]*N
y_compress={}
for j,y in enumerate(xy2):
  i = y & mask
  y >>= 40
  x = y & mask
  x -= 10**9
  y >>= 40
  y -= 10**9
  y_order[i] = j
  y_compress[y] = j+1

xy2 = []
for i in range(N):
  x,y = xy[i]
  x += 10**9
  y += 10**9
  xy2.append(x<<80 | y << 40 | i)
  
xy2 = sorted(xy2)
mask = (1<<40)-1
bit=BIT(N)
ans = 0
for x in xy2:
  i = x & mask
  x >>= 40
  y = x & mask
  y -= 10**9
  x >>= 40
  x -= 10**9
  
  y = y_compress[y]
  bit.add(y,1)
  '''
  今現在みている点より左上と左下にある点の個数（今の点は含まない。以下同じ）。
  BITを使って求める。
  '''
  n1 = bit.query(y-1,N)-1
  n2 = bit.query(0,y)-1 
  '''
  右上と右下。座標圧縮の結果を利用。(N-y(座標圧縮済))はある点より上にある点の総数。
  そこからn1（走査済みの点の個数)を引くことで、まだ走査していない点の個数を求めることができる。
  '''
  n3 = N-y-n1 
  n4 = y-n2-1
  prod14 = (pow(2,n1,mod)-1)*(pow(2,n4,mod)-1)*pow(2,n2+n3,mod) %mod
  prod23 = (pow(2,n2,mod)-1)*(pow(2,n3,mod)-1)*pow(2,n1+n4,mod) %mod
  prod1234 = (pow(2,n1,mod)-1)*(pow(2,n4,mod)-1)*(pow(2,n2,mod)-1)*(pow(2,n3,mod)-1) %mod
  ans += pow(2,N-1,mod)+prod14+prod23-prod1234
  ans %= mod
  
print(ans)