N, H = map(int, input().split())
A = [0]*N
B = [0]*N
for i in range(N):
  A[i],B[i] = map(int, input().split())

a = max(A)
B.sort()
cnt = 0
for b in B:
  if b>a:
    H -= b
    cnt += 1
    if H<=0:
      break
if H>0:
  cnt += (H+a-1)//a
    

print(cnt)