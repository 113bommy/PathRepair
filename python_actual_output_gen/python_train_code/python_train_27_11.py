N=int(input())
S=[input() for i in range(N)]
for v in ['AC','WA','TLE','RE']:
  print('{} x {}'.format(v,s.count(v)))