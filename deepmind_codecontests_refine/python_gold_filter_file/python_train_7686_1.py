N = int(input())
A = list(map(int, input().split()))


def judge(k):
  cnt = sum(max((a+k+1)//(N+1),0) for a in A)
  return cnt <= k

if judge(0):
  print(0)
  exit(0)

low = 0
high = 10**18

while low + 1 < high:
  mid = (low+high)//2
  if judge(mid):
    high = mid
  else:
    low = mid

r = high

for i in range(max(r-N*N,0),r):
  if judge(i):
    r = i
    break

print(r)