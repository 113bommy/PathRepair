import itertools
N = int(input())
LX, LY = [], []
RX, RY = [], []
DX, DY = [], []
UX, UY = [], []

for _ in range(N):
  x,y,d = input().split()
  x,y = int(x), int(y)
  if d == 'L':
    LX.append(x)
    LY.append(y)
  elif d == 'R':
    RX.append(x)
    RY.append(y)
  elif d == 'U':
    UX.append(x)
    UY.append(y)
  else:
    DX.append(x)
    DY.append(y)

INF = 10**18
fixed_x = [min(UX + DX + [INF]), max(UX + DX + [-INF])]
fixed_y = [min(LY + RY + [INF]), max(LY + RY + [-INF])]

R_x = [min(RX + [INF]), max(RX + [-INF])]
L_x = [min(RX + [INF]), max(RX + [-INF])]
U_y = [min(UY + [INF]), max(UY + [-INF])]
D_y = [min(DY + [INF]), max(DY + [-INF])]


# 2点が衝突する時刻を除けば1次関数
T = [0]

for x1,x2 in itertools.product(L_x, R_x):
  if x1 in [-INF, INF] or x2 in [-INF, INF]:
    continue
  T.append((x1 - x2) / 2)
for x1,x2 in itertools.product(L_x, fixed_x):
  if x1 in [-INF, INF] or x2 in [-INF, INF]:
    continue
  T.append(x1 - x2)
for x1,x2 in itertools.product(R_x, fixed_x):
  if x1 in [-INF, INF] or x2 in [-INF, INF]:
    continue
  T.append(x2 - x1)
  
for x1,x2 in itertools.product(D_y, U_y):
  if x1 in [-INF, INF] or x2 in [-INF, INF]:
    continue
  T.append((x1 - x2) / 2)
for x1,x2 in itertools.product(D_y, fixed_y):
  if x1 in [-INF, INF] or x2 in [-INF, INF]:
    continue
  T.append(x1 - x2)
for x1,x2 in itertools.product(U_y, fixed_y):
  if x1 in [-INF, INF] or x2 in [-INF, INF]:
    continue
  T.append(x2 - x1)
  
T = sorted(set(t for t in T if t >= 0))
T.append(10 ** 9)

def calc_x(t):
  # t秒後の横幅
  right = fixed_x[1]
  left = fixed_x[0]
  for x in [R_x[1]+t, L_x[1]-t]:
    if right < x:
      right = x
  for x in [R_x[0]+t, L_x[0]-t]:
    if left > x:
      left = x
  return right - left

def calc_y(t):
  # t秒後の横幅
  right = fixed_y[1]
  left = fixed_y[0]
  for y in [U_y[1]+t, D_y[1]-t]:
    if right < y:
      right = y
  for y in [U_y[0]+t, D_y[0]-t]:
    if left > y:
      left = y
  return right - left

def F(x1,x2,y1,y2):
  # x は x1からx2に向かう1次関数
  # y は y1からy2に向かう1次関数
  # t in [0,1] で関数を作る
  # x = (x2-x1)t + x1
  # y = (y2-y1)t + y1
  p,q,r,s = x2-x1, x1, y2-y1, y1
  a,b,c = p*r, p*s + q*r, q*s
  # f(t) = at^2 + bt + c
  if a <= 0:
    # 直線 or 上に凸
    return min(x1*y1, x2*y2)
  t0 = -b/(2*a)
  if t0 < 0 or t0 > 1:
    return min(x1*y1, x2*y2)
  return min(a*t0*t0 + b*t0 + c, a+b+c, c)
  
L = len(T)
X = [calc_x(t) for t in T]
Y = [calc_y(t) for t in T]

answer = 10 ** 18

for i in range(L-1):
  x1, x2 = X[i], X[i+1]
  y1, y2 = Y[i], Y[i+1]
  s = F(x1,x2,y1,y2)
  if answer > s:
    answer = s

print(answer)