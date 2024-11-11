def solve():
  n = int(input())
  a = list(map(int, input().split()))
  g, z = 0, 0
  cut = 1
  for i in range(n-1):
    if a[i+1] > a[i]:
      g += 1
    elif a[i+1] < a[i]:
      z += 1
    if g != 0 and z != 0:
      cut += 1
      g, z = 0, 0
  print(cut)
  return 0
 
if __name__ == "__main__":
  solve()
