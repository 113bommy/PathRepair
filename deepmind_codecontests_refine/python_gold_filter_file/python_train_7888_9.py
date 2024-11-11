N = int(input())

p = []
for i in range(N):
  a,b = map(int,input().split())
  p.append([max(0,a - b),a + b])
  
q = sorted(p,key=lambda x:x[1])  

cnt = 0
d = q[0][1]
for j,k in q[1:]:
  if j < d:
    cnt += 1
  else:
    d = k

print(N-cnt) 