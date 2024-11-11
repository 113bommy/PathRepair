n,m,v,p = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse=True)

#　せっかくなのであとでmarginを前計算してm*v以上をbisect
def isOK(x):
  border = a[x-1]
  if border + m < a[p-1]:
    return False
  elif x <= p:
    return True
  else:
    margin = m * n
    for i in range(p-1,x-1):
      margin -= a[i] - border
    if margin >= m*v:
      return True
    else:
      return False

def binary_search():
    ok = p-1
    ng = n+1
    while abs(ok-ng) > 1:
        mid = (ok+ng)//2
        if isOK(mid):
            ok = mid
        else:
            ng = mid
    return ok

ans = binary_search()  
print(ans)