N = int(input())
S = [input() for _ in range(N)]
ls = ["AC","WA","TLE","RE"]
for i in range(4):
  print("{} x {}".format(ls[i],S.count(ls[i])))