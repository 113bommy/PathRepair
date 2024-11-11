a,b=map(int,input().split())
h=[0,14]+list(range(2,14))
if a==b:
  print("Draw")
else:
  print("Alice"if h[a]>h[b]else"Bob")
