s=int(input())
G =[]
while (s not in G):
  G.append(s)
  if s % 2==0:
    s = int(s//2)
  else:
    s = int(3*s+1)
print(len(G)+1)