N = int(input())
s = [int(input()) for i in range(N)]
s.sort()
ans = sum(s)
if ans % 10 != 0:
  print(ans)
  exit()
else:
  for i in s:
    if i % 10 != 0:
      print(ans-i)
      exit()
print(0)