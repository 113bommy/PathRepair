import bisect
n = int(input())
ans = [-1*int(input())]
for i in range(n-1):
  a=int(input())
  a=-1*a
  if ans[-1]<=a:
    ans.append(a)
  else:
    b = bisect.bisect_right(ans,a)
    ans[b]=a
print(len(ans))