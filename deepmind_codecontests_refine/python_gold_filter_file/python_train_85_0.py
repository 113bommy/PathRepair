n,m = map(int, input().split())
st = []
pt = []
ch = []
for i in range(n):
  st.append(list(map(int, input().split())))
for i in range(m):
  pt.append(list(map(int, input().split())))
for j in st:
  for k in pt:
    d = abs(j[0]-k[0]) + abs(j[1]-k[1])
    ch.append(d)
  print(ch.index(min(ch))+1)
  ch = []