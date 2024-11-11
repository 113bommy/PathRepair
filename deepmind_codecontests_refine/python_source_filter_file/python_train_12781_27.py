a,b,c = map(int,input().split())
k = int(input())
for i in range(1,k+1):
  for j in range(k-i+1):
    if a<b*(2**i)<c*(2**j):
      print("Yes")
      quit()
print("No")