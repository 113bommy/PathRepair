r=0
for _ in[0]*int(input()):
  s,d=map(int,input().split())
  r=[(r-s+d)//d*d+s,s][r<s]
print(r)