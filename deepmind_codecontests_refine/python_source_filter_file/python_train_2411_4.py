coord = []
coef = {}
b = []
x = -11111
m = 0
coef_a = {}

n = int(input())
for i in range(n):
  coord.append(list(map(float, input().split())))

for i in range(n):
  x1, y1 = coord[i]
  for j in range(i+1,n):
    x2, y2 = coord[j]
    if x2 - x1:
      a = (y2-y1)/(x2-x1)
      b = (y1*x2-y2*x1)/(x2-x1)
      coef[(a,b)] = coef.get((a,b),0)+1
      coef_a[a] = coef_a.get(a,0)+1
      if coef[(a,b)] > 1:
        coef[(a,b)] -= 1 # del points on one line
        coef_a[a] -= 1
    else:
      if x2 != x:
        m += 1
      x = x2

coe = list(coef_a.values())
for i in range(len(coe)):
  coe[i] = coe[i]*(coe[i]-1)//2
l_par = sum(coe)
l_nmbr = len(coef) + m

ans = l_nmbr*(l_nmbr-1)//2 - m*(m-1)//2 - l_par
print(ans)