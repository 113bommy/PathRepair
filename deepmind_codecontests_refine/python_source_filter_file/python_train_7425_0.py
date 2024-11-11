n = int(input())
cur = ['']
for _ in range(n):
  s = input()
  if s[:3] == 'cd ' :
    _, path = s.split()
    paths = path.split('/')
    for direct in paths:
      if direct == '':
        continue
      elif direct == '..':
        cur.pop()
      else:
        cur += [direct]
  else:
    print('/'.join(cur) + '/')
  
