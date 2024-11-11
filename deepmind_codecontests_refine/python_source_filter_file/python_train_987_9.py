n , d = list(map(int,input().split()))
l = []
for i in range(n):
  m , s = list(map(int,input().split()))
  l.append([m , s])
l.sort()
i = 0
s = 0
m_x= 0
for k in range(n):
  s = l[k][1]
  while(l[k][0]-l[i][0] >= d):
    s += l[i][1]
    i += 1
  m_x = max(m_x , s)
print(m_x)