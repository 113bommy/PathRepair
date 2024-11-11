a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
g, h, i = map(int, input().split())
L = []
L.append({a, b, c})
L.append({d, e, f})
L.append({g, h, i})
L.append({a, d, g})
L.append({b, e, h})
L.append({c, f, i})
L.append({a, e, i})
L.append({c, f, i})
N = int(input())
B = {int(input()) for i in range(N)}
if any(l <= B for l in L):
  print("Yes")
else:
  print("No")