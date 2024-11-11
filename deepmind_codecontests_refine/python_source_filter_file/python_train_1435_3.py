import queue
I=lambda:map(int,input().split())
N,M=I()
ls=[[] for _ in range(M+1)]
for _ in[0]*M:
  A,B=I()
  ls[A]+=[B]
  ls[B]+=[A]
q = queue.Queue()
v=[-1]*(N+1)
v[0]=v[1]=0
q.put(1)
while not(q.empty()):
  top=q.get()
  for l in ls[top]:
    if v[l]<0:
      v[l]=top
      q.put(l)
if -1 in v:
  print("No")
else:
  print("Yes")
  [print(k) for k in v[2::]]