n = int(input())
a = [105, 135, 165, 189, 195]
count = 0
for i in a:
  if 1 <= i <= n:
    count += 1
print(count)
