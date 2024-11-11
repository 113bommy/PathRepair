N,M=map(int,input().split())
hoge=list(map(int,input().split()))

if sorted(hoge)[-M] >= sum(hoge)/(4*M):
  print('Yes')
else:
  print('No')
