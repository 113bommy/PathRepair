import sys
input = sys.stdin.readline
def inp():
    return(int(input()))

t = inp();
for i in range(t):
  n = inp()
  n_8=(n-1)//4+1
  mystr = ""
  for i in range(n - n_8):
    mystr+=str(9)
  for i in range(n_8):
    mystr+=str(8)
  print(int(mystr))
  