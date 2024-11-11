c, d = [int(i) for i in input().split(" ")]
n, m = [int(i) for i in input().split(" ")]
k = int(input())

s = n*m - k
s = max(s, 0)

if c < d*n:
  stuff = s//n
  try1 = c*stuff + d*(s-n*stuff)
  try2 = (c+1)*stuff
  print(min(try1, try2))
else:
  print(d*s)