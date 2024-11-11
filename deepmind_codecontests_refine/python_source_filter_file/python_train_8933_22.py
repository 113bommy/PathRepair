p=998244353
def getinv(n):
  inv = [0]*(n+1)
  #フェルマーの小定理より、a=1の時は1であることが分かる
  inv[1] = 1
  for i in range(2,n+1):
    #そのまま計算すると負になってしまうので、最後にmod pを取ることで正に戻す
    inv[i] = (-(p//a)*inv[p%a])%p
  return inv

def getCmb(n):
  #逆元を取得
  inv = getinv(n)
  #0 <= r <= n に対してnCrを求める
  nCr = [0]*(n+1)
  #r=0の時は、r-1が存在しないので与えておく
  nCr[0] = 1
  for i in range(1,n+1):
    #iで割る代わりにinv[i]をかけ、mod pを求める
    nCr[i] = (nCr[i-1]*(n-i+1)*inv[i])%p
  return nCr

def solve(n,a,b,k):
  nCr = getCmb(n)
  ans=0
  for i in range(n+1):
    #割り切れない時もあるが、その時は次の条件a*i+b*j==kで弾かれるので問題ない
    j = (k-a*i)//b
    #条件に一致するものを選ぶ。jの範囲に注意
    if a*i + b*j == k and 0<=j<=n:
      ans+= (nCr[i]*nCr[j])%p
      ans%= p
  return ans

n,a,b,k=map(int,input().split())
print(solve(n,a,b,k))