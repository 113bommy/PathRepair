import math

n = int(input())
for _ in range(n):
  a,b = input().split(" ")
  a,b = sorted([int(a), int(b)])
  c = math.ceil((a*b)**0.5)-1
  print(2*c-(a!=b)-(c*(c+1)>=b*b))