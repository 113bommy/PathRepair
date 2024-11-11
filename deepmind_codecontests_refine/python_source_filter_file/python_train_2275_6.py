N = int(input())
A = list(map(int,input().split()))
if sum(A) % 2 == 0:
  print("Yes")
else:
  print("No")