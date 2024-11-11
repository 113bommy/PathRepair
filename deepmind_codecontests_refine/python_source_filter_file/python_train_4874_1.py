n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
diff = [a[i]-b[i] for i in range(n)]
if sum(diff) < 0:
  print(-1)
else:
  diff.sort()
  count = 0
  ans = 0
  for i in diff:
    if i<0:
      count += i
      ans += 1
    else:
      break
  for i in diff[::-1]:
    if count>=0:
      break
    else:
      count += i
      ans += 1
print(ans)
  