n = int(input())
A = list(map(int,input().split()))
A.sort()

m = 0
cnt = 0
for i in A:
  if(m != A[i]):
    m = A[i]
    cnt += 1

if(cnt % 2 == 0):
  cnt -= 1
print(cnt)
    