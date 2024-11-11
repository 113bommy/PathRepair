import math
q = int(input())
for i in range(q):
  n = int(input())
  a, b, c = map(int, input().split())
  l = input()
  r = l.count('R')
  p = l.count('P')
  s = l.count('S')
  nr = min(a,r) + min(p,b) + min(s,c)
  if nr >= math.ceil(n/2):
    print("YES")
    st = list()
    for j in range(n):
      if l[j] == 'R' and b > 0:
        st.append('P')
        b -= 1
        continue
      elif l[j] == 'P' and c > 0:
        st.append('S')
        c -= 1
        continue
      elif l[j] == 'S' and a > 0:
        st.append('R')
        a -= 1
        continue
      else:
        st.append(' ')
    for j in range(st.count(' ')):
      index = st.index(' ')
      if a > 0:
        st[index] = 'R'
        a -= 1
      elif b > 0:
        st[index] = 'P'
        b -= 1
      elif c > 0:
        st[index] = 'S'
        c -= 1
    print(*st,sep='')
  else:
    print("NO")