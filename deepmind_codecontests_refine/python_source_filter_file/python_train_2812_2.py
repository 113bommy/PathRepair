n = int(input())
S = list(map(int, input().split()))
q = int(input())
T = list(map(int, input().split()))
cnt = 0
for i in T:
 a = 0
 b = n-1
 while b >= a:
  mid = (a + b) // 2
  if S[mid] == i:
   cnt += 1
   break
  elif S[mid] > i:
   b = mid
   continue
  else:
   a = mid + 1
   continue
print(str(cnt))