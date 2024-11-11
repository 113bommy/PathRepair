N,M=map(int,input().split())
h={i for i in range(1,M+1)}
for _ in range(N):
  a=list(map(int,input().split()))
  a=set(a[1:])
  h&=a
print(len(h))