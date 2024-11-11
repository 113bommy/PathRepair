n, a, b, c = map(int, input().split())

v = {
  'A': a,
  'B': b,
  'C': c
}
ss = []
for _ in range(n):
  ss.append(input())

history = [] 
flag = True
  
for i in range(n):
  
  s = ss[i]
  
  if v[s[0]] == 0 and v[s[1]] == 0:
    flag = False
    break
  elif v[s[0]] > v[s[1]]:
    history.append(s[1])
    v[s[0]] -= 1
    v[s[1]] += 1
  elif v[s[0]] < v[s[1]]:
    history.append(s[0])
    v[s[0]] += 1
    v[s[1]] -= 1
  elif i == n-1:
    history.append(s[0])
    v[s[0]] += 1
    v[s[1]] -= 1
  elif s[0] in ss[i+1]:
    history.append(s[0])
    v[s[0]] += 1
    v[s[1]] -= 1
  else:
    history.append(s[1])
    v[s[0]] -= 1
    v[s[1]] += 1
if flag:
  print("Yes")
  print('\n'.join(history))
else:
  print("No")