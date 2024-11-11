a, b = map(int, input().split())

ans = [["#" if i < 50 else "." for _ in range(100)] for i in range(100)]

for i in range(a - 1):
  rows = i // 50
  clms = (i % 50) * 2 + (rows % 2)
  ans[rows][clms] = "."

for i in range(b - 1):
  rows = i // 50
  clms = (i % 50) * 2 + (rows % 2)
  ans[99 - rows][clms] = "#"
  
print(100, 100)
for a in ans:
  print("".join(a))