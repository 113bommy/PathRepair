n = input()
k = int(input())
dp0 = [0] * 4
dp1 = [1,0,0,0]
for i in n:
  i = int(i)
  pdp0,pdp1,dp0 = dp0,dp1,[0]*4
  if i != 0:
    dp1 = [0] + pdp1[:-1]
  else:
    dp1 = pdp1
  dp0[0] = pdp0[0]+(i!=0)*pdp1[0]
  for j in range(1,4):
    dp0[j] = 9*pdp0[j-1] + pdp0[j] + (i-1)*pdp1[j-1] + (i!=0)*pdp1[j]
print(dp0[k]+dp1[k])