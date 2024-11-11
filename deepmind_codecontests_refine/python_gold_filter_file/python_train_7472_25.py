N = int(input())

#INF = float('inf')

def check(A):
  th = 0 #高さの合計
  for i in range(len(A)):
    b = A[i][0]
    h = A[i][1]
    if th + b < 0:
      return False
    else:
      th += h
  return True
    

L = []
R = []
goukei = 0
for i in range(N):
  temp = str(input())
  b= 0 #最下点
  h = 0 #ゴールの位置
  for j in range(len(temp)):
    if temp[j] == "(":
      h += 1
    else:
      h -= 1
    b = min(b,h)
  if h > 0:
    L.append([b,h])
  else:
    R.append([b-h,-h])
  goukei += h

L.sort(reverse=True)
R.sort(reverse=True)
#print(L,R)

if check(L) and check(R) and goukei == 0:
  print("Yes")
else:
  print("No")