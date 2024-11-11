n = int(input())
p = [int(input()) for i in range(n)]
q = [0]*(n+1)
for i in range(n):
  q[p[i]] = i
cnt = 0
m = 0
for i in range(1, n):
  if q[i]<q[i+1]:
    cnt += 1
    m = max(m, cnt)
  else:
    cnt = 1
print(n-m)