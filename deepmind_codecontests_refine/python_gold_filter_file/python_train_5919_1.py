n = int(input())
line = list(map(int,input().split()))
count = 1
up = False
down =False
for i in range(n - 1):
  if line[i] < line[i + 1]:
    up = True
  elif line[i] > line[i + 1]:
    down = True
  if up == down == True:
    count += 1
    up =False
    down =False
print(count)