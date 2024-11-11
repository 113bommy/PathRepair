f=int(input())
for q in range(f):
  a,b=map(int,input().split())
  n=a*60+b
  print(1440-n)