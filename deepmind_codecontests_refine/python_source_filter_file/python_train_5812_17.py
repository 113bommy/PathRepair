n,t = map(int,input().split())
m = 9999
for i in range(n):
  c,y = map(int,input().split())
  if y<t:
    m=min(m,c)
print("TLE" if m==9999 else m)