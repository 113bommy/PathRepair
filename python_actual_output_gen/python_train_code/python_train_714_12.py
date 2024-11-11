a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input)
s=v-w
s*=t
if abs(a-b)<=s:
  print("YES")
else:
  print("NO")