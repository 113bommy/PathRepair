N = int(input())
S = input()
a = 0
b = S.count('.')
num = min(N - y, y)
for i in range(N):
  x = S[i] =='#'
  a += x
  b -= 1-x
  num = num(num, a+b)
print(num)
