n,m,k=map(int,input().split())
M=10**9+7
def combi(x,y):
  c=1
  m=min(x-y,y)
  for iii in range(y):
    c=c*(x-iii)*pow(y-iii,-1)%M
  return c

rem_combi=combi(n*m-2,k-2)

def calc(num):
  out=0
  for iii in range(num):
    out+=iii*(num-iii)%M
  return out

x_cost=m*m*calc(n)%M
y_cost=n*n*calc(m)%M
ans=rem_combi*(x_cost+y_cost)%M
print(int(ans))