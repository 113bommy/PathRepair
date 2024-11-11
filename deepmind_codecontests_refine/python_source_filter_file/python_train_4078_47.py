def solve():
  from sys import stdin
  line = stdin.readline
  a,b=map(int,line().split())
  print(pow(2,a+b,99824435))
solve()