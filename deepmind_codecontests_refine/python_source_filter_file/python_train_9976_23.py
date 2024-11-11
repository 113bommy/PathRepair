x = int(input())
ans = [b**p for b in range(33) for p in range(2,10)
      if b**p < x]
print(max(ans))    