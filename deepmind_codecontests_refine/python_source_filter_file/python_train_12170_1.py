from math import gcd
while True:
  try:
    n = int(input())
    if not n: break
    lst = [[]]
    weight = [-1 for i in range(n + 1)]
    def setWeight(n):
      p,q,r,b = lst[n]
      if weight[n] != -1:pass
      elif r == 0 and b == 0:
        weight[n] = (p + q) // gcd(p,q)
      elif r == 0:
        setWeight(b)
        wb = weight[b]
        g = gcd(wb * q, p)
        lcm = wb * q * p // g
        weight[n] = lcm // q + lcm // p
        print("wr:",str(lcm//p),"wb:",str(wb),"g:",g,"p:",p,"lcm",lcm)
      elif b == 0:
        setWeight(r)
        wr = weight[r]
        g = gcd(wr * p, q)
        lcm = wr * p * q // g
        weight[n] = lcm // p + lcm // q
      else:
        if weight[r] == -1: setWeight(r)
        if weight[b] == -1: setWeight(b)
        wr = weight[r]
        wb = weight[b]
        g = gcd(wr * p, wb * q)
        lcm = wr * p * wb  * q // g
        weight[n] = lcm // p + lcm // q
    for i in range(n):
      lst.append(list(map(int,input().split())))
    for i in range(0,n):
      if weight[i + 1] == -1:
        setWeight(i+1)
    print(max(weight))
    print(weight)
  except EOFError:
    break


