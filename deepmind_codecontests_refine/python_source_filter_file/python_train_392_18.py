N=int(input())
a=[int(input()) for i in range(N)]
b=sorted(a)[::-1]
for i in range(N):
  if a[i]=b[0]:
    print(b[1])
  else:
    print(b[0])
    