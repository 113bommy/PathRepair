N,T=0,0
for i in range(int(input())):
  N,T=map(int,input().split())
  if N&1:
    T^=127
  print(T+(N-1)*127)