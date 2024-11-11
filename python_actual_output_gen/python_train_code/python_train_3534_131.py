k = int(input())
a,b = map(int,input().split())

if b-a > k or a%k==0:
  print("OK")
else:
  print("NG")