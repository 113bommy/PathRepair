N=int(input())
l=list(map(int,input().split()))
if 2*max(l)<sum(l):
  print("Yes")
else:
  print("No")