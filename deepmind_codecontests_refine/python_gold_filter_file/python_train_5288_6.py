a,b=map(int,input().split())
c,d,e=map(int,input().split())
g=input()
l = a-b
for i in range(l):
   if g[i] == g[i+b]:
      g = g[:i+b] + 'a' + g[i+1+b:]
      
else:
  R = g.count('r')
  S = g.count('s')
  P = g.count('p')
  answer = c*S+d*P+e*R
  print(answer)