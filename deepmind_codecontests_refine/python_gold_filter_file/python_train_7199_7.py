n = int(input())
a = list(map(int, input().split()))
c = list(map(int, input().split()))
b = dict(zip(c, range(n)))
pos_one = b[1] if 1 in b else -1

if 1 in b:
  is_sorted = True
  for i in range(pos_one+1, n):
    if c[i] != c[i-1] + 1:
      is_sorted = False
      break
  
  if is_sorted:
    num_next = c[-1]+1
    flag = True
    for i in range(n):
      if c[i] == 1:
        break 
      if num_next in b and b[num_next] >= (num_next - (c[-1]+1)):
        flag = False
        break
      num_next += 1
    if flag:
      print(pos_one)
      exit(0)


max_pos = pos_one+1 if 1 in b else 0
for i in range(2, n+1):
  if i in b and b[i] >= pos_one+i:
    max_pos = max(max_pos, b[i]-i+2)

print(max_pos+n)
