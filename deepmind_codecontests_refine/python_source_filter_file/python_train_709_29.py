n = int(input())
a = list(map(int, input().split()))
k = 0
g = 0
for i in a:
  if(i%4 == 0):g+=1
  if(i%2 == 1):k+=1
print(g,k)
if(g>=k or (g+1>=k and g+k==n)):print("Yes")
else:print("No")