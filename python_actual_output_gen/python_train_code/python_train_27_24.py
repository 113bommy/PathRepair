n = int(input())
s = [input() for _ in range(n)]
l = ["AC","WA","TLE","RE"]
for i in range(4):  print(l[i],"X",s.count(l[i]))