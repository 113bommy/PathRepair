A, B = map(int, input().split())

print(100, 100)
big = max(A, B)
small = min(A, B)

ans = ['#'*100, '.#'*50]

b = 1
s = 1
flag = False
for i in range(98):
  if s + 50 <= small:
    ans.append(['#.', '.#'][i%2]*50)
    b += 50
    s += 50
  elif s < small < s + 50:
    l = small - s
    ans.append(['#.', '.#'][i%2]*l + '..'*(50-l))
    flag = True
    b += l
    s += l
  elif flag:
    ans.append('.'*100)
    flag = False
  else:
    if b + 50 <= big:
      ans.append('#.'*50)
      b += 50
    elif b < big < b + 50:
      l = big - b
      ans.append('#.'*l + '..'*(50-l))
      b += l
    else:
      ans.append('.'*100)
    flag = True

for i in range(100):
  if A > B:
    print(ans[i].replace('#', '_').replace('.', '#').replace('_', '.'))
  else:
    print(ans[i])