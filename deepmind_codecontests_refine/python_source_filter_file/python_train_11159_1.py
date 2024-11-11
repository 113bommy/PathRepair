n = int(input())

ceil = False
import math

for _ in range(n):
  nr = int(input())

  if (nr % 2) == 0:
    print (n // 2)
  else:
    ans = math.floor(nr / 2)
    if(ceil):
      ans += 1
    ceil = not ceil

    print(ans)