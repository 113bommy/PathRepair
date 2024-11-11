sal
n,q = map(int, input().split())
s = input()
l = [0]*(n+1)
for i in range(1,n):
  if s[i-1:i+1] == "AC":
    l[i] = l[i-1]+1
  else:
    l[i] = l[i-1]
for _ in range(q):
  a,b = map(int, input().split())
  print(l[b-1]-l[a-1])
