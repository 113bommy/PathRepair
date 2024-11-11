n=int(input())
s=[input() for i in range(n)]
for i in ['AC','WA','TLE','RE']:
  print('{0} x {1}'.format(i,s.count(i)))
