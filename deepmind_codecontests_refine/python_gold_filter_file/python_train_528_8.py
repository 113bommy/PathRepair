n = int(input())

for i in range(n):
  x, y, k = map(lambda x: abs(int(x)), input().split(" "))
  x, y = min(x,y), max(x,y)
  minstep = y

  ans = 0
  if k < minstep:
    ans = -1
  else:
    ans += x
    k -= x
    if x == y:
      if k%2 == 1:
        ans -= 1
        k -= 1
      ans += k
    else:
      if (y-x)%2 == 1:
        y -= 1
        k -= 1
        #print(ans)
        ans += k
      else:
        #print(k, ans)
        if k%2 == 0:
          ans += k
        else:
          ans += k-2
  print(ans)