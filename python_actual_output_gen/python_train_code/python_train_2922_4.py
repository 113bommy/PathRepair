r=0
for _ in[0]*int(input()):
  s,d=map(int,input().split())
  r=[s,(r-s+d)//d*d+s][r>s]
print(r)