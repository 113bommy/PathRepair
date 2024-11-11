a,v=map(int, input().split())
b,w=map(int, input().split())
t=int(input())

if abs(v-w)*t>abs(a-b):
  print("NO")
else:
  print("YES")