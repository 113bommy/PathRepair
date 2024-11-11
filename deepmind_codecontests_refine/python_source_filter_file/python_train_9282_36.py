def ii():
  return int(input())
def ss():
  return [x for x in input()]
def si():
  return [int(x) for x in input().split()]
def mi():
  return map(int, input().split())

a, b, c = mi()
if a <= b + c:
  print("YES")
else:
  print("NO")