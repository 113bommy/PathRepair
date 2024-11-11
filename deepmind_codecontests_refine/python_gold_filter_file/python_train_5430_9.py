import sys
input = sys.stdin.readline

n,m = map(int,input().split())
v = list(map(int,input().split()))
lo = -1; hi = m 
while(lo + 1< hi) : 
  mid = (hi + lo) // 2
  prev = 0; ok = 1
  for i in v : 
    if i < prev : 
      if i + mid < prev :
        ok = 0
        break
    elif i > prev :
      if (m - i + prev > mid) :
        prev = i
  if ok : hi = mid
  else : lo = mid
print(hi) 