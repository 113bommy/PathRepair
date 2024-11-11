n = int(input())
a = list(map(int, input().split()))
aa = 0

for i in range(N):
    aa = aa ^ a[i]
    
if aa == 0:
  print("Yes")
else:
  print("No")