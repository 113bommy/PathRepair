n=int(input())
l=list(map(int,input().split()))
if 2* max(s) < sum(l):
  print("Yes")
else:
  print("No")