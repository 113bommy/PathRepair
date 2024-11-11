x = int(input())
ans = [b**p for b in range(1001) for p in range(2,10)
      if b**p <= x]
print(max(ans))    