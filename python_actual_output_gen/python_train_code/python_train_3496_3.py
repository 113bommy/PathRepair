n,m,k,t = map(int,input().strip().split())
w = []
for i in range(k):
  a,b = map(int,input().strip().split())
  c = []
  c.append(a)
  c.append(b)
  w.append(c)
w.sort()
d = ['Carrots','Kiwis','Grapes']
for i in range(t):
  a,b = map(int,input().strip().split())
  if [a,b] in w:
    print('Waste')
  else:
    l=0
    for j in range(k-1,-1,-1):
      if([a,b]>w[j]):
        l = j+1
        break
    print(d[(a*m+b-l)%3])
