n,k=map(int,input().split())
s=set()
for i in range(n):
  s.add(int("".join(map(str,input().split(" ")))))
for i in s:
  for j in s:
    if i&j==0:
      print("YES")
      exit()
print("NO")