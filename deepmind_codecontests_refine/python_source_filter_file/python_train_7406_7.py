# B. Maximal Continuous Rest
HrNo = int(input())
HrStr = [int (x) for x in input().split()]
HrStr = HrStr + HrStr[:HrNo]

count = 0
Maxi = 0
for i in range(HrNo):
  if HrStr[i] == 1 and HrStr[i+1] == 1:
    count += 1
    if count > Maxi:
      Maxi = count
  else:
    count = 0

if Maxi > 0:
  print (Maxi+1)
elif 1 in HrStr:
  print(1)
else:
  print (0)
