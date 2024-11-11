N = int(input())
all = 0
colors = [0] * 8
for a in map(int, input().split()):
  if a >= 3200:
    all += 1
  else:
    colors[a // 400] = 1
print(sum(colors), sum(colors) + all)