T=int(input())
for i in range(T):
  N,a,b,c,d=map(int, input().split())
  memo={}
  memo[0]=0
  memo[1]=d
  
  def f(n):
    if n in memo:
      return memo[n]
    e2,e3,e5=n%2,n%3,n%5
    dd=min(d*n,d*e2+a+f((n-e2)//2),d*e2+a+f((n+e2)//2),d*e3+b+f((n-e3)//3),d*(3-e3)+b+f((n+3-e3)//3),d*e5+c+f((n-e5)//5),d*(5-e5)+c+f((n+5-e5)//5))
    memo[n]=dd
    return dd
  print(f(N))