N = int(input())
X = int(-(-N//1.08))
print(X)
if N == int(X * 1.08):
  print(X)
else:
  print(':(')