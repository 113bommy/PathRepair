import sys
input = sys.stdin

line = input.readline()
n = int(line)
line = input.readline()
d = list(map(int,line.split(" ")))
maxn = maxc = max(d)
minn = minc = min(d)

ans = []
for num in d:
  if num == maxc:
    maxc = None
  elif num == minc:
    minc = None
  else:
    ans.append(str(num))

ans.sort()
print(maxn, end=" ")
for num in ans:
  print(num, end=" ")
print(minn)
